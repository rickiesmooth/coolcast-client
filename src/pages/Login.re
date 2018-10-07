open BsReactNative;

let component = ReasonReact.statelessComponent("login");

let text = ReasonReact.string;

/* <Signup key="eee" /> */

let make = _children => {
  ...component,
  render: _self =>
    <Layout>
      <View>
        <GatsbyLink key="e" to_="/">
          {ReasonReact.string("Home")}
        </GatsbyLink>
      </View>
    </Layout>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));