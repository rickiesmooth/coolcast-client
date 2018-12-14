open BsReactNative;
open Context;
open GlobalStyles;

type action =
  | Query(string);

type state = {query: string};

let component = ReasonReact.reducerComponent("Chat");

let styles =
  StyleSheet.create(
    Style.{"main": style([position(Relative), flex(1.0)])},
  );

/*
 * make query for users chats
 * of no chats send should create new chat > newChat element
 * else it should add message to chat > existingChat element
 */

let make = (~chatId, _children) => {
  ...component,
  initialState: () => {query: ""},
  reducer: action =>
    switch (action) {
    | Query(q) => (_state => ReasonReact.Update({query: q}))
    },
  render: _self => <Text value=chatId />,
};