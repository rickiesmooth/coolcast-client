open BsReactNative;

let styles =
  StyleSheet.create(
    Style.{
      "wrapper":
        style([
          width(Pct(100.0)),
          height(Pct(100.0)),
          /* backgroundColor(String("blue")), */
          flexDirection(Row),
        ]),
      "left":
        style([
          flexDirection(Column),
          flex(1.),
          maxWidth(Pt(220.)),
          height(Pct(100.0)),
          backgroundColor(String("purple")),
        ]),
      "right":
        style([
          flexDirection(Column),
          flex(1.),
          height(Pct(100.0)),
          /* backgroundColor(String("red")), */
        ]),
    },
  );

type action =
  | Query(string);

type state = {
  query: string,
  newMessage: bool,
};

let component = ReasonReact.reducerComponent("Messenger");

let make = _children => {
  ...component,
  initialState: () => {query: "", newMessage: true},
  reducer: action =>
    switch (action) {
    | Query(q) => (state => ReasonReact.Update({...state, query: q}))
    },
  render: self =>
    <View style=styles##wrapper>
      <View style=styles##left> <Text value="haha left" /> </View>
      <View style=styles##right>
        /* {self.state.newMessage === true ? <NewMessage /> : <ChatId chatId />} */

          <TextInput
            placeholder="type name"
            onChangeText={e => self.send(Query(e))}
          />
        </View>
    </View>,
};