open Paper;
open ReactNative;

let styles =
  Style.(
    StyleSheet.create({
      "appbar": style(~zIndex=1000, ()),
      "siteInner": viewStyle(~paddingBottom=55.->dp, ()),
    })
  );
[@react.component]
let default = (~children) => {
  let (windowHeight, setWindowHeight) =
    React.useState(() => Dimensions.get(`window)##height);

  Dimensions.addEventListener(`change, d =>
    setWindowHeight(_ => d##window##height)
  );

  let navbarHeight = 55.0;
  let totalHeight = windowHeight -. navbarHeight;

  <ApolloHooks.Provider client=Apollo.client>
    <Appbar style=styles##appbar>
      <Appbar.BackAction onPress={_event => Gatsby.Link.navigate(-1)} />
      <Search />
    </Appbar>
    <MusicPlayer>
      <ScrollView
        style=Style.(
          array([|style(~height=totalHeight->dp, ()), styles##siteInner|])
        )>
        children
      </ScrollView>
      <AudioPlayer />
    </MusicPlayer>
  </ApolloHooks.Provider>;
};