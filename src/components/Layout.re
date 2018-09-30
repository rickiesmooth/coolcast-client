open BsReactNative;
open Belt;

let component = ReasonReact.statelessComponent("Layout");

let meta = [|
  Helmet.metaField(~name="description", ~content="Sample"),
  Helmet.metaField(~name="keywords", ~content="sample, something"),
|];

let make = children => {
  ...component,
  render: _self =>
    <View>
      <Helmet title="Coolcast" meta />
      <div>
        <Header siteTitle="CoolCast" />
        {ReasonReact.array(children)}
      </div>
    </View>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));