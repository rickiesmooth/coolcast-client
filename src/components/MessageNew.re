open BsReactNative;
open GatsbyLink;
open GlobalStyles;

type action =
  | Query(string);

type state = {query: string};

let component = ReasonReact.reducerComponent("MessageNew");

let make = _children => {
  ...component,
  initialState: () => {query: ""},
  reducer: action =>
    switch (action) {
    | Query(q) => (_state => ReasonReact.Update({query: q}))
    },
  render: _self =>
    <View style=Styles.containerSmall>
      <TextInput
        placeholder="type name"
        onChangeText={
          e => {
            Js.log(e);
            ();
          }
        }
      />
    </View>,
};

/* <Userlist /> */