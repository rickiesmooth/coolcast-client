open BsReactNative;

let component = ReasonReact.statelessComponent("index");

let text = ReasonReact.string;

let make = _children => {
  ...component,
  render: _self =>
    <Layout>
      <GatsbyLink key="e" to_="/login">
        {ReasonReact.string("siteTitle")}
      </GatsbyLink>
      <Text key="ḧ" value="Hi people" />
    </Layout>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));