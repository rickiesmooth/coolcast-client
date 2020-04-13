/** fetch more */
module Podcast = [%graphql
  {|
  query getPersonsOlderThan($id: ID! $next: String) {
    getPodcast(input: {id: $id, next: $next}) {
      id
      title
      description
      thumbnail
      next
      episodes {
        id
        title
        audio
        description
      }
    }
  }
|}
];

let fetchMoreUpdateQuery =
    (prevResult: Js.Json.t, options: ApolloHooks.Query.updateQueryOptions) => {
  let mergeResults: (Js.Json.t, option(Js.Json.t)) => Js.Json.t = [%bs.raw
    {|
    function (prevResult, fetchMoreResult) {
        if (!fetchMoreResult) return prevResult;
        return {
            ...fetchMoreResult,
            getPodcast: {
                ...fetchMoreResult.getPodcast,
                episodes: prevResult.getPodcast.episodes.concat(fetchMoreResult.getPodcast.episodes)
            }
        };
      }
    |}
  ];
  mergeResults(prevResult, options->ApolloHooks.Query.fetchMoreResultGet);
};