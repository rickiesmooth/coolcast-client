open BsReactNative;

module Styles = {
  open Style;

  let containerCentered =
    style([width(Pct(100.0)), flex(1.), alignSelf(Center)]);

  let paddedSmallVertical = style([paddingVertical(Pt(16.))]);

  let containerSmall =
    Style.concat([containerCentered, style([maxWidth(Pt(480.))])]);

  let containerDefault =
    Style.concat([containerCentered, style([maxWidth(Pt(960.))])]);

  let inputDefault =
    Style.concat([paddedSmallVertical, style([color(String("#FFF"))])]);
};