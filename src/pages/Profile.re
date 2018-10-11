open BsReactNative;
open GatsbyLink;

let component = ReasonReact.statelessComponent("profile");

let text = ReasonReact.string;

let make = _children => {
  ...component,
  render: _self =>
    <Shell>
      <View style=GlobalStyles.Styles.containerSmall>
        <Text value="Profile page" />
        <Button
          title="logout"
          onPress={
            () =>
              Js.Promise.(
                AsyncStorage.clear()
                |> then_(() => navigate("/") |> resolve)
                |> ignore
              )
          }
        />
      </View>
    </Shell>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));