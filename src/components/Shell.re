open BsReactNative;
open Context;

let component = ReasonReact.statelessComponent("Shell");

let styles =
  StyleSheet.create(
    Style.{
      "container":
        style([
          maxWidth(Pt(960.)),
          width(Pct(100.0)),
          display(Flex),
          alignSelf(Center),
        ]),
    },
  );

let make = (~user: option(Context.user)=?, children) => {
  ...component,
  render: _self =>
    <View>
      <Header siteTitle="CoolCast" user />
      <View style=styles##container> ...children </View>
    </View>,
};