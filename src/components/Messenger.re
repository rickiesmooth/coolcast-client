open BsReactNative;

let styles =
  StyleSheet.create(
    Style.{
      "wrapper":
        style([
          width(Pct(100.0)),
          height(Pct(100.0)),
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
        style([flexDirection(Column), flex(1.), height(Pct(100.0))]),
    },
  );

type navigationState =
  | MessagesHome
  | MessageNew
  | MessageNewTo(string)
  | MessageActive(string);

type action =
  | Navigate(navigationState);

type state = {currentPage: navigationState};

let urlToShownPage = (url: ReasonReact.Router.url) =>
  switch (url.path) {
  | [] => MessagesHome
  | [_] => MessagesHome
  | [_, id, ...rest] =>
    ignore(rest);
    switch (id, url.search) {
    | ("new", "") => MessageNew
    | ("new", search) => MessageNewTo(search)
    | _ => MessageActive(id)
    };
  };

let component = ReasonReact.reducerComponent("Messenger");

let make = _children => {
  ...component,
  initialState: () => {
    currentPage:
      urlToShownPage(ReasonReact.Router.dangerouslyGetInitialUrl()),
  },
  didMount: self => {
    let token =
      ReasonReact.Router.watchUrl(url =>
        self.send(Navigate(urlToShownPage(url)))
      );
    self.onUnmount(() => ReasonReact.Router.unwatchUrl(token));
  },
  reducer: (action, _state) =>
    switch (action) {
    | Navigate(page) => ReasonReact.Update({currentPage: page})
    },
  render: self => {
    let body =
      switch (self.state.currentPage) {
      | MessagesHome => <Chat chatId="n/a" />
      | MessageNew => <UserSearch />
      | MessageNewTo(userId) => <NewMessage userId />
      | MessageActive(chatId) => <Chat chatId />
      };
    <View style=styles##wrapper>
      <View style=styles##left>
        <Button
          title="newMessage"
          onPress={() => ReasonReact.Router.push("/messages/new")}
        />
        <RecentChatsQuery />
        <Text value="hey" />
      </View>
      <View style=styles##right> body </View>
    </View>;
  },
};