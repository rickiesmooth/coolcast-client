let component = ReasonReact.statelessComponent("signup");

let text = ReasonReact.string;

let make = _children => {
  ...component,
  render: _self => <Shell> <Signup /> </Shell>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));