open BsReactNative;
open Context;
open GlobalStyles;

type action =
  | Query(string)

type state = {
  query: string,
};

let component = ReasonReact.reducerComponent("Chat");

let styles =
  StyleSheet.create(
    Style.{"main": style([position(Relative), flex(1.0)])},
  );

let make = (~newMessage: option(bool)=?, children) => {
  ...component,
  initialState: () => {query: ""},
  reducer: action =>
    switch (action) {
    | Query(q) => (state => ReasonReact.Update({...state, query: q}))
    },
  render: self =>
    <View>
        <TextInput
            placeholder="type name"
            onChangeText={e => self.send(Query(e))}
            style=Styles.inputDefault
        />
      <UserSearch query={self.state.query}/>
    </View>,
};