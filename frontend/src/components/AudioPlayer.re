open ReactNative;

let styles =
  Style.(
    StyleSheet.create({
      "container":
        viewStyle(
          ~backgroundColor="red",
          ~position=`absolute,
          ~bottom=0.->dp,
          ~height=55.->dp,
          ~width=100.->pct,
          ~justifyContent=`flexStart,
          ~alignItems=`center,
          ~margin=auto,
          (),
        ),
    })
  );

[@react.component]
let make = () => {
  let (_playing, currentTrackName, currentSource, _play, _currentlyPlaying) =
    UseMusicPlayer.useMusicPlayer();

  switch (currentSource) {
  | Some(p) =>
    <TouchableOpacity onPress={_e => Js.log(p)}>
      <View style=styles##container>
        <Text> currentTrackName->React.string </Text>
      </View>
    </TouchableOpacity>
  | None => <View />
  };
};