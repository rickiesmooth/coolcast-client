open BsReactNative;

let component = ReasonReact.statelessComponent("login");

let text = ReasonReact.string;

let make = _children => {
  ...component,
  render: _self =>
    <Layout>
      <GatsbyLink key="e" to_="/">
        {ReasonReact.string("siteTitle")}
      </GatsbyLink>
      <Text key="ḧ" value="Hi Login" />
    </Layout>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));