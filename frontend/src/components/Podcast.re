open ReactNative;

let str = ReasonReact.string;

let styles =
  Style.(
    StyleSheet.create({
      "headerRow": viewStyle(~flexDirection=`row, ()),
      "headerRowMeta":
        viewStyle(
          ~flexDirection=`column,
          ~flex=1.0,
          ~justifyContent=`center,
          ~marginLeft=16.->dp,
          (),
        ),
      "button": viewStyle(~zIndex=1, ()),
      "text": textStyle(~textTransform=`uppercase, ()),
      "image": style(~width=340.->dp, ~height=340.->dp, ()),
    })
  );

// module PodcastQuery = ApolloHooks.useQuery(PodcastGraphql.Podcast.definition);

[@react.component]
let default = (~id) => {
  let (_playing, _currentTrackName, _currentSource, _play, changeSource) =
    UseMusicPlayer.useMusicPlayer();

  // let getPodcast = PodcastGraphql.Podcast.make(~id, ());
  let (_simple, full) =
    ApolloHooks.useQuery(
      ~variables=PodcastGraphql.Podcast.makeVariables(~id, ~next="", ()),
      ~notifyOnNetworkStatusChange=true,
      PodcastGraphql.Podcast.definition,
    );

  let handleLoadMore = (~next) => {
    let getNextPage = PodcastGraphql.Podcast.make(~id, ~next, ());
    full.fetchMore(
      ~variables=getNextPage##variables,
      ~updateQuery=PodcastGraphql.fetchMoreUpdateQuery,
      (),
    )
    |> ignore;
  };
  <Container
    result=full
    renderData={data => {
      let episodes = data##getPodcast##episodes;
      let list =
        Array.map(
          episode =>
            <TouchableOpacity key=episode##id>
              <Paper.List.Item
                onPress={_ => {
                  Js.log("press");
                  changeSource(
                    Some({name: episode##title, src: episode##audio}),
                  );
                }}
                title=episode##title
                description=episode##description
                left={Paper.List.renderIcon((props: Paper.List.iconProps) =>
                  <Paper.List.Icon icon="play" color={props.color} />
                )}
              />
            </TouchableOpacity>,
          episodes,
        )
        ->React.array;

      <ScrollView>
        <View style={styles##headerRow}>
          <Image
            style={styles##image}
            source={Image.Source.fromUriSource(
              Image.uriSource(~uri={data##getPodcast##thumbnail}, ()),
            )}
          />
          <View style=styles##headerRowMeta>
            <Paper.Title> {data##getPodcast##title->str} </Paper.Title>
            <Paper.Title> {data##getPodcast##description->str} </Paper.Title>
          </View>
        </View>
        <Paper.List.Section title="Episodes"> list </Paper.List.Section>
        <Paper.Button
          style={styles##button}
          mode=`contained
          loading={full.networkStatus === FetchMore}
          onPress={_ => handleLoadMore(~next=data##getPodcast##next)}>
          "load more"->str
        </Paper.Button>
      </ScrollView>;
    }}
  />;
};