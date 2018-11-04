open BsReactNative;
open GatsbyLink;

let component = ReasonReact.statelessComponent("messages");

let text = ReasonReact.string;

let make = _children => {
  ...component,
  render: _self =>
    <Shell>
      <Text value="Messages page" />
      <Messenger />
    </Shell>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));