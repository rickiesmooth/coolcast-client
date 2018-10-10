open BsReactNative;

let component = ReasonReact.statelessComponent("profile");

let text = ReasonReact.string;

let make = _children => {
  ...component,
  render: _self =>
    <Layout>
      <Text value="User page user page user page user page" />
      <Button title="logout" onPress={() => ignore(AsyncStorage.clear())} />
    </Layout>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));