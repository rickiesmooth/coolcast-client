// Env.re
[@bs.val] external apiUrl: string = "process.env.GATSBY_API_URL";
[@bs.val] external apiKey: string = "process.env.GATSBY_API_KEY";

let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

let contextHandler = () => {
  let headers = {
    "headers": {
      "x-api-key": apiKey,
    },
  };
  headers;
};

let httpLink = ApolloLinks.createHttpLink(~uri=apiUrl, ());

let contextLink = ApolloLinks.createContextLink(contextHandler);

let client =
  ReasonApollo.createApolloClient(
    ~link=ApolloLinks.from([|contextLink, httpLink|]),
    ~cache=inMemoryCache,
    (),
  );