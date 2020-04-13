type jsIconProps = {. "color": string};

type iconProps = {color: string};

type renderIcon = jsIconProps => React.element;

let renderIcon = (reRenderIcon: iconProps => React.element): renderIcon =>
  (jsIconProps: jsIconProps) => reRenderIcon({color: jsIconProps##color});

module Icon = {
  [@bs.module "react-native-paper"] [@bs.scope "List"] [@react.component]
  external make:
    (~color: string=?, ~icon: string, ~style: ReactNative.Style.t=?) =>
    React.element =
    "Icon";
};

module Accordion = {
  [@bs.module "react-native-paper"] [@bs.scope "List"]
  external reactClass: ReasonReact.reactClass = "Accordion";

  [@bs.deriving abstract]
  type props = {
    title: string,
    [@bs.optional]
    description: string,
    [@bs.optional]
    left: renderIcon,
    [@bs.optional]
    theme: Paper_ThemeProvider.appTheme,
    [@bs.optional]
    style: ReactNative.Style.t,
  };

  let make = (~title, ~description=?, ~left=?, ~theme=?, ~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=props(~title, ~description?, ~left?, ~theme?, ~style?, ()),
      children,
    );
};

module Item = {
  [@bs.module "react-native-paper"] [@bs.scope "List"] [@react.component]
  external make:
    (
      ~title: string,
      ~description: string=?,
      ~left: renderIcon=?,
      ~right: renderIcon=?,
      ~onPress: ReactNative.Event.pressEvent => unit=?,
      ~theme: Paper_ThemeProvider.appTheme=?,
      ~style: ReactNative.Style.t=?
    ) =>
    React.element =
    "Item";
};

module Section = {
  [@bs.module "react-native-paper"] [@bs.scope "List"] [@react.component]
  external make:
    (
      ~title: string=?,
      ~theme: Paper_ThemeProvider.appTheme=?,
      ~children: React.element
    ) =>
    React.element =
    "Section";
};