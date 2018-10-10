open BsReactNative;

let component = ReasonReact.statelessComponent("index");

let text = ReasonReact.string;

let make = _children => {
  ...component,
  render: _self =>
    <Layout>
      <View>
        <Text
          value=" homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage"
        />
      </View>
    </Layout>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));