let initialState: SharedTypes.state = {
  source: None,
  playing: NotPlaying,
  audioPlayer: Audio.Sound.make(),
};

let obj1 = Audio.config(~shouldPlay=true);

type action =
  | Pause
  | Play
  | AudioPlayer(Audio.Sound.t)
  | CurrentlyPlaying(option(SharedTypes.podcast));

let withPause = (state): SharedTypes.state => {
  ...state,
  playing: NotPlaying,
};

let withPlay = (state: SharedTypes.state) => {...state, playing: Playing};

let withAudioPlayer = (state: SharedTypes.state, audioPlayer: Audio.Sound.t) => {
  {...state, audioPlayer};
};

let withCurrentlyPlaying =
    (state: SharedTypes.state, source: option(SharedTypes.podcast)) => {
  ...state,
  source,
};

let reducer = (state: SharedTypes.state, action) =>
  switch (action) {
  | Pause => withPause(state)
  | Play => withPlay(state)
  | AudioPlayer(player) => withAudioPlayer(state, player)
  | CurrentlyPlaying(podcast) => withCurrentlyPlaying(state, podcast)
  };

let musicPlayerContext = React.createContext((initialState, ignore));
let musicPlayerContextProvider = React.Context.provider(musicPlayerContext);

module MusicPlayerProvider = {
  let makeProps = (~value, ~children, ()) => {
    "value": value,
    "children": children,
  };
  let make = React.Context.provider(musicPlayerContext);
};

[@react.component]
let make = (~children) => {
  let (state, dispatch) = React.useReducer(reducer, initialState);

  let instance = state.audioPlayer;
  // React.useEffect1(
  //   () =>
  //     switch (state.playing) {
  //     | Playing =>
  //       instance##playAsync() |> ignore;
  //       None;
  //     | NotPlaying =>
  //       instance##playAsync() |> ignore;
  //       None;
  //     },
  //   [|state.playing|],
  // );

  React.useEffect1(
    () =>
      switch (state.source) {
      | Some(source) =>
        instance##loadAsync(source.src, obj1) |> ignore;
        None;
      | _ =>
        instance##unloadAsync() |> ignore;
        None;
      },
    [|state.source|],
  );

  <MusicPlayerProvider value=(state, dispatch)>
    children
  </MusicPlayerProvider>;
};