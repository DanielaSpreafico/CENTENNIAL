/*
* Copyright (c) 2016 Wipro Ltd. and others. All rights reserved.
*
* This program and the accompanying materials are made available under the
* terms of the Eclipse Public License v1.0 which accompanies this distribution,
* and is available at http://www.eclipse.org/legal/epl-v10.html
*/

package org.opendaylight.mwtn.eventmanager.impl;

import org.opendaylight.controller.md.sal.binding.api.MountPoint;
import org.opendaylight.controller.md.sal.binding.api.MountPointService;
import org.opendaylight.controller.md.sal.binding.api.NotificationService;
import org.opendaylight.controller.sal.binding.api.BindingAwareBroker.ProviderContext;
import org.opendaylight.controller.sal.binding.api.BindingAwareProvider;
import org.opendaylight.controller.sal.binding.api.RpcConsumerRegistry;
import org.opendaylight.mwtn.eventmanager.api.EventManagerService;
import org.opendaylight.mwtn.eventmanager.impl.listener.MicrowaveEventListener;
import org.opendaylight.mwtn.eventmanager.impl.xml.XmlMapper;
import org.opendaylight.yang.gen.v1.urn.ietf.params.xml.ns.netconf.notification._1._0.rev080714.CreateSubscriptionInputBuilder;
import org.opendaylight.yang.gen.v1.urn.ietf.params.xml.ns.netconf.notification._1._0.rev080714.NotificationsService;
import org.opendaylight.yang.gen.v1.urn.ietf.params.xml.ns.netconf.notification._1._0.rev080714.StreamNameType;
import org.opendaylight.yang.gen.v1.urn.opendaylight.netconf.node.topology.rev150114.network.topology.topology.topology.types.TopologyNetconf;
import org.opendaylight.yang.gen.v1.urn.opendaylight.params.xml.ns.yang.websocketmanager.rev150105.WebsocketmanagerService;
import org.opendaylight.yang.gen.v1.urn.tbd.params.xml.ns.yang.network.topology.rev131021.NetworkTopology;
import org.opendaylight.yang.gen.v1.urn.tbd.params.xml.ns.yang.network.topology.rev131021.NodeId;
import org.opendaylight.yang.gen.v1.urn.tbd.params.xml.ns.yang.network.topology.rev131021.TopologyId;
import org.opendaylight.yang.gen.v1.urn.tbd.params.xml.ns.yang.network.topology.rev131021.network.topology.Topology;
import org.opendaylight.yang.gen.v1.urn.tbd.params.xml.ns.yang.network.topology.rev131021.network.topology.TopologyKey;
import org.opendaylight.yang.gen.v1.urn.tbd.params.xml.ns.yang.network.topology.rev131021.network.topology.topology.Node;
import org.opendaylight.yang.gen.v1.urn.tbd.params.xml.ns.yang.network.topology.rev131021.network.topology.topology.NodeKey;
import org.opendaylight.yangtools.yang.binding.InstanceIdentifier;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.google.common.base.Optional;

//TODO
//Implement EventManagerService in another class
public class EventManagerImpl implements EventManagerService, BindingAwareProvider, AutoCloseable {

	private static final Logger LOG = LoggerFactory.getLogger(EventManagerImpl.class);
	private static final InstanceIdentifier<Topology> NETCONF_TOPO_IID = InstanceIdentifier
			.create(NetworkTopology.class)
			.child(Topology.class, new TopologyKey(new TopologyId(TopologyNetconf.QNAME.getLocalName())));
	private ProviderContext session;

	private WebsocketmanagerService websocketmanagerService;
	private XmlMapper xmlMapper;

	@Override
	public void onSessionInitiated(ProviderContext session) {
		LOG.info("EventManagerImpl Session Initiated");
		this.session = session;
		websocketmanagerService = session.getRpcService(WebsocketmanagerService.class);
		xmlMapper = new XmlMapper();
	}

	@Override
	public void close() throws Exception {
		LOG.info("EventManagerImpl closing");
	}

	@Override
	public void startListenerOnNode(String nodeName) {
		LOG.info("Starting Event listener on Netconf device :: Name : {}", nodeName);

		MountPointService mountService = session.getSALService(MountPointService.class);
		InstanceIdentifier<Node> instanceIdentifier = NETCONF_TOPO_IID.child(Node.class,
				new NodeKey(new NodeId(nodeName)));
		Optional<MountPoint> mountPoint = null;
		int timeout = 10000;

		do {
			mountPoint = mountService.getMountPoint(instanceIdentifier);
			LOG.info("Event listener waiting for mount point for Netconf device :: Name : {}", nodeName);
			try {
				Thread.sleep(1000);
				timeout -= 1000;
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		} while (!mountPoint.isPresent() && timeout > 0);

		if (timeout < 0) {
			LOG.warn("Event listener timeout while waiting for mount point for Netconf device :: Name : {} ", nodeName);
			return;
		}

		Optional<NotificationService> service1 = mountPoint.get().getService(NotificationService.class);

		MicrowaveEventListener microwaveEventListener = new MicrowaveEventListener(nodeName, websocketmanagerService,
				xmlMapper);
		service1.get().registerNotificationListener(microwaveEventListener);

		final String streamName = "NETCONF";
		final Optional<RpcConsumerRegistry> service = mountPoint.get().getService(RpcConsumerRegistry.class);
		final NotificationsService rpcService = service.get().getRpcService(NotificationsService.class);
		final CreateSubscriptionInputBuilder createSubscriptionInputBuilder = new CreateSubscriptionInputBuilder();
		createSubscriptionInputBuilder.setStream(new StreamNameType(streamName));
		LOG.info("Event listener triggering notification stream {} for node {}", streamName, nodeName);
		rpcService.createSubscription(createSubscriptionInputBuilder.build());
	}

	@Override
	public void removeListenerOnNode(String nodeName) {
		LOG.info("Removing Event listener on Netconf device :: Name : {}", nodeName);
		// ODL automatically removes
	}
}
