module BrowserRouter = {
  [@bs.module "@reach/router"]
  external browserRouter: ReasonReact.reactClass = "Router";
  let make = children =>
    ReasonReact.wrapJsForReason(
      ~reactClass=browserRouter,
      ~props=Js.Obj.empty(),
      children,
    );
};