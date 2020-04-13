open Paper;
open ReactNative;

let str = ReasonReact.string;

let styles =
  Style.(
    StyleSheet.create({"image": style(~width=60.->dp, ~height=60.->dp, ())})
  );

module GetSearchResults = [%graphql
  {|
  query getSearchResults($query: String!) {
    getSearchResults(query: $query) {
      title
      id
      thumbnail
    }
  }
|}
];

[@react.component]
let make = (~query) => {
  // let config = GetSearchResults.make(~query, ());
  // let (_simple, full) =
  //   SearchResultsQuery.use(~variables=config##variables, ());

  let (_simple, full) =
    ApolloHooks.useQuery(
      ~variables=GetSearchResults.makeVariables(~query, ()),
      GetSearchResults.definition,
    );
  <Container
    result=full
    renderData={data =>
      switch (data##getSearchResults) {
      | None => React.null
      | Some(results) =>
        let list =
          Array.map(
            podcast =>
              switch (podcast) {
              | Some(podcast) =>
                <Gatsby.Link key=podcast##id _to={"/podcast/" ++ podcast##id}>
                  <List.Item
                    title=podcast##title
                    left={_ =>
                      <Image
                        style={styles##image}
                        source={Image.Source.fromUriSource(
                          Image.uriSource(~uri={podcast##thumbnail}, ()),
                        )}
                      />
                    }
                  />
                </Gatsby.Link>
              | None => React.null
              },
            results,
          )
          ->React.array;
        <List.Section> list </List.Section>;
      }
    }
  />;
};