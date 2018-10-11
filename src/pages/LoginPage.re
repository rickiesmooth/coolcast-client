open BsReactNative;

let component = ReasonReact.statelessComponent("login");

let text = ReasonReact.string;

let make = _children => {
  ...component,
  render: _self => <Shell> <View> <Login /> </View> </Shell>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));