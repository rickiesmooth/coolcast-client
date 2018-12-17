open BsReactNative;

let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

let contextHandler = () => {
  let token =
    switch (Dom.Storage.(localStorage |> getItem("cc_token"))) {
    | None => ""
    | Some(t) => t
    };

  let headers = {
    "headers": {
      "authorization": token,
    },
  };
  headers;
};

let contextLink = ApolloLinks.createContextLink(contextHandler);

/* let httpLink =
   ApolloLinks.createHttpLink(
     ~uri="https://cc-api-nrzvvn7l9.now.sh/graphql",
     (),
   ); */
let httpLink =
  ApolloLinks.createHttpLink(~uri="https://cc-api.now.sh/graphql", ());

/* WebSocket client */
let webSocketLink =
  ApolloLinks.webSocketLink(
    ~uri="wss://cc-ws-api.now.sh",
    ~reconnect=true,
    (),
  );

/* based on test, execute left or right */
let webSocketHttpLink =
  ApolloLinks.split(
    operation => {
      let operationDefition =
        ApolloUtilities.getMainDefinition(operation##query);
      operationDefition##kind == "OperationDefinition"
      &&
      operationDefition##operation == "subscription";
    },
    webSocketLink,
    httpLink,
  );

let instance =
  ReasonApollo.createApolloClient(
    ~link=ApolloLinks.from([|contextLink, webSocketHttpLink|]),
    ~cache=inMemoryCache,
    (),
  );