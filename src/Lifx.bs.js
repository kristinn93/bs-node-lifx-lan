// Generated by BUCKLESCRIPT VERSION 4.0.5, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Future = require("reason-future/src/Future.bs.js");
var FutureJs = require("reason-future/src/FutureJs.bs.js");
var Belt_List = require("bs-platform/lib/js/belt_List.js");
var NodeLifxLan = require("node-lifx-lan");

function optionsToJs(param) {
  return {
          duration: param[/* duration */0]
        };
}

function optionsFromJs(param) {
  return /* record */[/* duration */param.duration];
}

function handleError(prim) {
  return String(prim);
}

function discover(lifx) {
  return Future.mapError(Future.mapOk(FutureJs.fromPromise(lifx.discover(), handleError), Belt_List.fromArray), (function () {
                return /* Error */Block.__(1, ["asdf"]);
              }));
}

NodeLifxLan.turnOffBroadcast({
      duration: /* duration */1000
    });

exports.optionsToJs = optionsToJs;
exports.optionsFromJs = optionsFromJs;
exports.handleError = handleError;
exports.discover = discover;
/*  Not a pure module */
