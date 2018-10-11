open BsReactNative;

let component = ReasonReact.statelessComponent("signup");

let text = ReasonReact.string;

let make = _children => {
  ...component,
  render: _self =>
    <Shell>
      <View>
        <Signup />
        <GatsbyLink to_="/"> <Text value="home" /> </GatsbyLink>
      </View>
    </Shell>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));