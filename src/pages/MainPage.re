open BsReactNative;

let component = ReasonReact.statelessComponent("index");

let text = ReasonReact.string;

let make = _children => {
  ...component,
  render: _self =>
    <Layout>
      <View>
        <GatsbyLink key="e" to_="/login">
          {ReasonReact.string("siteTitle")}
        </GatsbyLink>
      </View>
    </Layout>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));