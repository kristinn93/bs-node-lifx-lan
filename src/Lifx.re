type t;
[@bs.module] external make: t = "node-lifx-lan";

[@bs.deriving {jsConverter: newType}]
type options = {duration: int};
[@bs.send] external turnOnAll: (t, abs_options) => unit = "turnOnBroadcast";
let turnOnAll = (~options=?, ()) =>
  Belt.Option.getWithDefault(options, {duration: 100})
  |> optionsToJs
  |> turnOnAll(make);
[@bs.send] external turnOffAll: (t, abs_options) => unit = "turnOffBroadcast";
let turnOffAll = (~options=?, ()) =>
  Belt.Option.getWithDefault(options, {duration: 100})
  |> optionsToJs
  |> turnOffAll(make);
type light;
type error;

[@bs.send] external turnOnBulb: light => unit = "turnOn";
[@bs.send] external turnOffBulb: light => unit = "turnOff";

[@bs.send] external discover: t => Js.Promise.t(array(light)) = "";
let handleError = Js.String.make;
let discover = () =>
  discover(make)
  ->(FutureJs.fromPromise(handleError))
  ->(Future.mapOk(value => Belt.List.fromArray(value)))
  ->(
      Future.mapError(_err => {
        Js.log(_err);
        Belt.Result.Error("asdf");
      })
    );
