open BsReactNative;
open Context;
open GlobalStyles;

let component = ReasonReact.statelessComponent("Layout");

let meta = [|
  Helmet.metaField(~name="description", ~content="Sample"),
  Helmet.metaField(~name="keywords", ~content="sample, something"),
|];

let styles =
  StyleSheet.create(
    Style.{"main": style([position(Relative), flex(1.0)])},
  );

let make = (~user: option(Context.user)=?, children) => {
  ...component,
  render: _self =>
    <View style=styles##main>
      <Helmet title="Coolcast" meta />
      <Header siteTitle="CoolCast" user />
      <View style=Styles.containerDefault> ...children </View>
    </View>,
};