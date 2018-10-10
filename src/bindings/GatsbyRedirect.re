[@bs.module "@reach/router"]
external gatsbyRedirect: ReasonReact.reactClass = "Redirect";

[@bs.deriving abstract]
type jsProps = {
  [@bs.as "to"]
  to_: string,
  from: Js.nullable(string),
  noThrow: Js.nullable(bool),
};

let make =
    (
      ~to_: string,
      ~from: option(string)=?,
      ~noThrow: option(bool)=?,
      children,
    ) => {
  let jsProps =
    jsProps(
      ~to_,
      ~from=Js.Nullable.fromOption(from),
      ~noThrow=Js.Nullable.fromOption(noThrow),
    );
  ReasonReact.wrapJsForReason(
    ~reactClass=gatsbyRedirect,
    ~props=jsProps,
    children,
  );
};