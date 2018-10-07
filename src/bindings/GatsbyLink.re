[@bs.module "gatsby"] external gatsbyLink: ReasonReact.reactClass = "Link";

[@bs.module "gatsby"] external withPrefix: string => string = "withPrefix";
[@bs.module "gatsby"] external navigate: string => unit = "navigate";
[@bs.deriving abstract]
type jsProps = {
  [@bs.as "to"]
  to_: string,
  activeStyle: Js.nullable(ReactDOMRe.Style.t),
  style: Js.nullable(ReactDOMRe.Style.t),
  innerRef: Js.nullable(ReasonReact.reactRef),
  onClick: Js.nullable(ReactEvent.Mouse.t => unit),
  activeClassName: Js.nullable(string),
  exact: Js.nullable(bool),
  strict: Js.nullable(bool),
};

let make =
    (
      ~to_: string,
      ~activeStyle: option(ReactDOMRe.Style.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      ~innerRef: option(ReasonReact.reactRef)=?,
      ~onClick: option(ReactEvent.Mouse.t => unit)=?,
      ~activeClassName: option(string)=?,
      ~exact: option(bool)=?,
      ~strict: option(bool)=?,
      children,
    ) => {
  let jsProps =
    jsProps(
      ~to_,
      ~activeStyle=Js.Nullable.fromOption(activeStyle),
      ~innerRef=Js.Nullable.fromOption(innerRef),
      ~style=Js.Nullable.fromOption(style),
      ~onClick=Js.Nullable.fromOption(onClick),
      ~activeClassName=Js.Nullable.fromOption(activeClassName),
      ~exact=Js.Nullable.fromOption(exact),
      ~strict=Js.Nullable.fromOption(strict),
    );
  ReasonReact.wrapJsForReason(
    ~reactClass=gatsbyLink,
    ~props=jsProps,
    children,
  );
};

let navigate = navigate;

let withPrefix = withPrefix;