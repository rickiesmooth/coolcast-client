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
          borderColor(String("#f58c93")),
          borderWidth(1.),
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
  | Query(string)
  | NewMessage;

type state = {
  query: string,
  newMessage: bool,
};

let component = ReasonReact.reducerComponent("Messenger");

let make = _children => {
  ...component,
  initialState: () => {query: "", newMessage: false},
  reducer: action =>
    switch (action) {
    | Query(q) => (state => ReasonReact.Update({...state, query: q}))
    | NewMessage => (state => ReasonReact.Update({...state, newMessage: true}))
    },
  render: self =>
    <View style=styles##wrapper>
      <View style=styles##left>
      <Button
          title="newMessage"
          onPress={
            () => self.send(NewMessage)
          }
        />
      </View>
      <View style=styles##right>
          <Chat newMessage={self.state.newMessage} />
        </View>
    </View>,
};