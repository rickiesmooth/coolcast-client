open BsReactNative;

let component = ReasonReact.statelessComponent("signup");

let text = ReasonReact.string;

let make = _children => {
  ...component,
  render: _self =>
    <Layout>
      <View>
        <Signup />
        <GatsbyLink to_="/"> {ReasonReact.string("Home")} </GatsbyLink>
      </View>
    </Layout>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));