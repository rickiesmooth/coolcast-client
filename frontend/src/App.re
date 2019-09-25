open ReactNative;

let containerStyle =
  Style.(
    style(
      ~flex=1.,
      ~backgroundColor="#F5FCFF",
      ~alignItems=`center,
      ~justifyContent=`center,
      (),
    )
  );

let welcomeStyle =
  Style.(style(~fontSize=20., ~textAlign=`center, ~margin=10.->dp, ()));

[@react.component]
let app = () => {
  let (inputText, setInputText) = React.useState(() => "");

  <View style=containerStyle>
    <Text style=welcomeStyle> "Coolcast"->ReasonReact.string </Text>
    <TextInput
      placeholder="search podcast.."
      value=inputText
      onChangeText={text => setInputText(_ => text)}
    />
  </View>;
};