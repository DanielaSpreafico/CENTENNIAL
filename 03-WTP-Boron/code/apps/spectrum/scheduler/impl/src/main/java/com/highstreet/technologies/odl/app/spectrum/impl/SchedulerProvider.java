/*
 * Copyright © 2015 ZTE and others.  All rights reserved.
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v1.0 which accompanies this distribution,
 * and is available at http://www.eclipse.org/legal/epl-v10.html
 */
package com.highstreet.technologies.odl.app.spectrum.impl;

import com.fasterxml.jackson.databind.JsonNode;
import com.highstreet.technologies.odl.app.spectrum.impl.api.Communicator;
import com.highstreet.technologies.odl.app.spectrum.impl.api.DataAgent;
import com.highstreet.technologies.odl.app.spectrum.impl.api.MosAgent;
import com.highstreet.technologies.odl.app.spectrum.impl.api.RestfulODLCommunicator;
import com.highstreet.technologies.odl.app.spectrum.impl.meta.DN;
import com.highstreet.technologies.odl.app.spectrum.impl.meta.Pair;
import com.highstreet.technologies.odl.app.spectrum.impl.meta.Result;
import com.highstreet.technologies.odl.app.spectrum.impl.task.SpectrumTask;
import org.opendaylight.controller.sal.binding.api.BindingAwareBroker;
import org.opendaylight.controller.sal.binding.api.BindingAwareBroker.ProviderContext;
import org.opendaylight.controller.sal.binding.api.BindingAwareProvider;
import org.opendaylight.yang.gen.v1.urn.opendaylight.params.xml.ns.yang.scheduler.rev150105.SchedulerService;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.net.Authenticator;
import java.net.MalformedURLException;
import java.net.PasswordAuthentication;
import java.util.ArrayList;
import java.util.List;

import static com.highstreet.technologies.odl.app.spectrum.impl.primitive.Singleton.getInstance;

public class SchedulerProvider implements BindingAwareProvider, AutoCloseable
{
    private static final Logger LOG = LoggerFactory.getLogger(SchedulerProvider.class);

    static
    {
        Authenticator.setDefault(new Authenticator()
        {
            @Override
            protected PasswordAuthentication getPasswordAuthentication()
            {
                return new PasswordAuthentication("admin", "admin".toCharArray());
            }
        });

    }

    private BindingAwareBroker.RpcRegistration<SchedulerService> schedulerService;

    @Override
    public void onSessionInitiated(ProviderContext session)
    {
        schedulerService = session.addRpcImplementation(SchedulerService.class, new SchedulerRpc());

        getInstance(TaskFactory.class).register("test", () ->
                new SpectrumTask(new DataAgent()
                {

                    @Override
                    public Object get(DN dnAgent, String attrName)
                    {
                        return 700;
                    }

                    @Override
                    public List<String> ls(DN dnAgent) throws Exception
                    {
                        return new ArrayList<>();
                    }
                }, new Communicator()
                {
                    @Override
                    public Result<JsonNode> ls(String path, String targetName)
                    {
                        return null;
                    }

                    @Override
                    public Object get(String dn, String attrName)
                    {
                        return 750;
                    }

                    @Override
                    public void set(String dn, Pair<String, Object>... values)
                    {
                        for (Pair<String, Object> value : values)
                        {
                            LOG.info("setting " + value.first() + "with value: " + value.second().toString() + " to ne");
                        }
                    }

                }));

        getInstance(TaskFactory.class).register("spectrum", () ->
        {
            try
            {
                return new SpectrumTask(new MosAgent("http://localhost:8282/mos"), new RestfulODLCommunicator());
            } catch (MalformedURLException e)
            {
                LOG.warn("", e);
                return null;
            }
        });

        LOG.info("TaskFactory initiated");
        LOG.info("SchedulerProvider Session Initiated");
    }

    @Override
    public void close() throws Exception
    {
        LOG.info("SchedulerProvider Closed");
        if (schedulerService != null)
            schedulerService.close();
    }
}
