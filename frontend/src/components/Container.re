open ReactNative;
open ApolloHooks;

let str = React.string;

[@react.component]
let make =
    (
      ~result: ApolloHooks.Query.queryResult('a),
      ~renderData: 'a => React.element,
    ) => {
  switch (result) {
  | {loading: true, data: None} => <ActivityIndicator />
  | {data: Some(data)} => renderData(data)
  | {error: Some(error)} =>
    <Paper.Title> {error##message->str} </Paper.Title>
  | {error: None, data: None, loading: false} =>
    <Paper.Title> "Not asked"->str </Paper.Title>
  };
};