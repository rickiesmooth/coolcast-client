[@bs.module "modal-enhanced-react-native-web"]
external enhancedModal: ReasonReact.reactClass = "ReactNativeModal";

[@bs.deriving abstract]
type jsProps = {
  /* some example fields */
  isVisible: Js.nullable(int),
};

let make = (~isVisible=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=enhancedModal,
    ~props=jsProps(~isVisible=Js.Nullable.fromOption(isVisible)),
    children,
  );