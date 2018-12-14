open BsReactNative;
open GlobalStyles;

type state = {query: string};

type action =
  | Query(string);

let component = ReasonReact.reducerComponent("AutoComplete");

let make = _children => {
  ...component,
  initialState: () => {query: ""},
  reducer: (action, _state) =>
    switch (action) {
    | Query(q) => ReasonReact.Update({query: q})
    },
  render: self =>
    <View>
      <TextInput
        placeholder="type name"
        onChangeText={e => self.send(Query(e))}
        style=Styles.inputDefault
      />
      {
        String.length(self.state.query) > 1 ?
          <UserQuery query={self.state.query} /> : ReasonReact.null
      }
    </View>,
};