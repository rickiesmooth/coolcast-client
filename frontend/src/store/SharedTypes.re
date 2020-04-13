type podcast = {
  name: string,
  src: string,
};

type playing =
  | Playing
  | NotPlaying;

type state = {
  audioPlayer: Audio.Sound.t,
  playing,
  source: option(podcast),
};