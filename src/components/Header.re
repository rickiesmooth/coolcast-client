open BsReactNative;
open Context;

let component = ReasonReact.statelessComponent("Header");

let styles =
  StyleSheet.create(
    Style.{
      "head": style([color(String("#ggg")), fontSize(Float(32.))]),
      "wrapper": style([marginBottom(Pt(15.))]),
      "header":
        style([
          maxWidth(Pt(960.)),
          backgroundColor(String("#eee")),
          paddingVertical(Pt(8.)),
          paddingHorizontal(Pt(16.)),
        ]),
    },
  );

let make = (~siteTitle: string, _children) => {
  ...component,
  render: _self =>
    <View style=styles##wrapper>
      <View style=styles##header>
        <Text style=styles##head value=siteTitle />
        <UserContext.Consumer>
          ...{text => <Text value=text />}
        </UserContext.Consumer>
      </View>
    </View>,
};