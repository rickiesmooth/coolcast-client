open BsReactNative;

module Styles = {
  open Style;

  let containerCentered = style([width(Pct(100.0)), alignSelf(Center)]);

  let paddedSmallVertical = style([paddingVertical(Pt(16.))]);

  let containerSmall =
    Style.concat([containerCentered, style([maxWidth(Pt(480.))])]);

  let containerDefault =
    Style.concat([containerCentered, style([maxWidth(Pt(960.))])]);
};