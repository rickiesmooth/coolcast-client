open BsReactNative;

let component = ReasonReact.statelessComponent("index");

let make = _children => {
  ...component,
  render: _self =>
    <Shell>
      <View>
        <Text
          value="homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage homepage"
        />
      </View>
    </Shell>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));