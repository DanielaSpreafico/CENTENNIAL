/*
 * Copyright (c) 2016 highstreet technologies GmbH and others.  All rights reserved.
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v1.0 which accompanies this distribution,
 * and is available at http://www.eclipse.org/legal/epl-v10.html
 */

define(['app/mwtnConnect/mwtnConnect.module','app/mwtnCommons/mwtnCommons.services'],function(mwtnConnectApp) {


  mwtnConnectApp.register.factory('$mwtnConnect', function($mwtnCommons, $mwtnDatabase, $mwtnLog) {

    var COMPONENT = '$mwtnConnect';
    $mwtnLog.info({component: COMPONENT, message: '$mwtnConnect started!'});

    var service = {};
    
    service.getAllData = $mwtnDatabase.getAllData;
    service.addRequiredNetworkElement = $mwtnCommons.addRequiredNetworkElement;
    service.getRequiredNetworkElements = $mwtnCommons.getRequiredNetworkElements
    service.getActualNetworkElements = $mwtnCommons.getActualNetworkElements;
    service.registerForOdlEvents = $mwtnCommons.registerForOdlEvents;
    
    service.mount = $mwtnCommons.mount;
    service.unmount = $mwtnCommons.unmount;
    
    return service;
  });

});
