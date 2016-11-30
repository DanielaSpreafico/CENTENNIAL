/*
 * Copyright (c) 2016 highstreet technologies GmbH and others. All rights reserved.
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v1.0 which accompanies this distribution,
 * and is available at http://www.eclipse.org/legal/epl-v10.html
 */

define(['angularAMD', 
        'app/routingConfig', 
        'app/core/core.services', 
        'common/config/env.module',
        'app/mwtnCommons/bower_components/angular-ui-grid/ui-grid.min', 
        'ui-bootstrap'], 
        function(ng) {
  var mwtnCommonsApp = angular.module('app.mwtnCommons', ['ui.grid', 'ui.bootstrap', 'app.core', 'ui.router.state','config', 'pascalprecht.translate']);

  mwtnCommonsApp.config(function($stateProvider, $compileProvider, $controllerProvider, $provide, NavHelperProvider, $httpProvider, $translateProvider, $translatePartialLoaderProvider) {
    mwtnCommonsApp.register = {
      controller : $controllerProvider.register,
      directive : $compileProvider.directive,
      factory : $provide.factory,
      service : $provide.service
    };

    $translatePartialLoaderProvider.addPart('app/mwtnCommons/locale/locale');


//    NavHelperProvider.addControllerUrl('app/mwtnCommons/mwtnCommons.controller');
//    NavHelperProvider.addToMenu('mwtnCommons', {
//     "link" : "#/mwtnCommons",
//     "active" : "main.mwtnCommons",
//     "title" : "MWTN Commons",
//     "icon" : "",  // Add navigation icon css class here
//     "page" : {
//        "title" : "MWTN Commons",
//        "description" : "mwtnCommons"
//     }
//    });

    var access = routingConfig.accessLevels;

//    $stateProvider.state('main.mwtnCommons', {
//        url: 'mwtnCommons',
//        access: access.admin,
//        views : {
//            'content' : {
//                templateUrl: 'src/app/mwtnCommons/mwtnCommons.tpl.html',
//                controller: 'mwtnCommonsCtrl'
//            }
//        }
//    });

  });

  return mwtnCommonsApp;
});
