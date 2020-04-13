open ReactNative;
let styles =
  Style.(
    StyleSheet.create({
      "results":
        style(
          ~margin=auto,
          ~top=54.->dp,
          ~position=`absolute,
          ~backgroundColor="#EEE",
          (),
        ),
      "input": style(~margin=auto, ()),
    })
  );

[@react.component]
let make = () => {
  let (inputText, setInputText) = React.useState(() => "");
  let (isBlurred, setIsBlurred) = React.useState(() => true);

  <View>
    <Paper.Searchbar
      style=styles##input
      placeholder="search podcast..."
      value=inputText
      onChangeText={text => setInputText(_ => text)}
    />
    {String.length(inputText) > 2
       ? <View style=styles##results> <Results query=inputText /> </View>
       : React.null}
  </View>;
};