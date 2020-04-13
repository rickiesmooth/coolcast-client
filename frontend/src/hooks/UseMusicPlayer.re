let useMusicPlayer = () => {
  let (state, dispatch) = React.useContext(MusicPlayer.musicPlayerContext);

  let playing = state.playing;
  let currentSource = state.source;

  let currentPodcastName =
    switch (state.source) {
    | Some(podcast) => podcast.name
    | None => ""
    };

  let play = () =>
    switch (playing) {
    | Playing => dispatch(MusicPlayer.Pause)
    | NotPlaying => dispatch(MusicPlayer.Play)
    };

  let changeSource = nextSource => {
    // order:
    // unload
    // override state
    switch (currentSource) {
    | Some(_) =>
      state.audioPlayer##unloadAsync()
      |> Js.Promise.then_(() => {
           dispatch(MusicPlayer.AudioPlayer(Audio.Sound.make()));
           Js.log("going to switch");

           dispatch(MusicPlayer.CurrentlyPlaying(nextSource));
           Js.Promise.resolve();
         })
      |> ignore
    | None => dispatch(MusicPlayer.CurrentlyPlaying(nextSource))
    };
  };

  (playing, currentPodcastName, currentSource, play, changeSource);
};