open BsReactNative;
open Context;
open GlobalStyles;

let component = ReasonReact.statelessComponent("Shell");

let make = (~user: option(Context.user)=?, children) => {
  ...component,
  render: _self =>
    <View>
      <Header siteTitle="CoolCast" user />
      <View style=Styles.containerDefault> ...children </View>
    </View>,
};