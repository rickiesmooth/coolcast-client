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
      <EnhancedModal isVisible=0> <Text value="haha" /> </EnhancedModal>
    </Shell>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));