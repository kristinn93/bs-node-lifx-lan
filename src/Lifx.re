type t;
[@bs.module] external lifx: t = "node-lifx-lan";

[@bs.deriving {jsConverter: newType}]
type options = {duration: int};
[@bs.send] external turnOnAll: (t, abs_options) => unit = "turnOnBroadcast";
[@bs.send] external turnOffAll: (t, abs_options) => unit = "turnOffBroadcast";
type light;
type error;

[@bs.send] external turnOnBulb: light => unit = "turnOn";
[@bs.send] external turnOffBulb: light => unit = "turnOff";

[@bs.send] external discover: t => Js.Promise.t(array(light)) = "";
let handleError = Js.String.make;
let discover = lifx =>
  discover(lifx)
  ->(FutureJs.fromPromise(handleError))
  ->(Future.mapOk(value => Belt.List.fromArray(value)))
  ->(Future.mapError(_err => Belt.Result.Error("asdf")));

/* turnOnAll(lifx, optionsToJs({duration: 1000})); */
turnOffAll(lifx, optionsToJs({duration: 1000}));
/*
 let bulbs =
   lifx
   ->discover
   ->(
       Future.get(res =>
         switch (res) {
         | Belt.Result.Ok(lights) =>
           lights->Belt.List.getExn(0)->Js.log;
           lights->Belt.List.getExn(0)->turnOffBulb;
         | Belt.Result.Error(msg) => msg->Js.log
         }
       )
     ); */