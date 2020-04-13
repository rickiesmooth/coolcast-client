[@bs.module "gatsby"] [@react.component]
external make:
  (~style: ReactNative.Style.t=?, ~_to: string, ~children: React.element) =>
  React.element =
  "Link";

[@bs.module "@reach/router"] external navigate: int => unit = "navigate";