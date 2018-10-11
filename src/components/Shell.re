open BsReactNative;
open Context;

type state =
  | Loaded(string)
  | Anonymous;

/* Action declaration */
type action =
  | Token(string);

let component = ReasonReact.reducerComponent("Layout");

let meta = [|
  Helmet.metaField(~name="description", ~content="Sample"),
  Helmet.metaField(~name="keywords", ~content="sample, something"),
|];

module GetUser = [%graphql
  {|
  query {
      me {
          id
          name
          email
      }
  }
|}
];

module GetUserQuery = ReasonApollo.CreateQuery(GetUser);

let userQuery = GetUser.make();

let make = children => {
  ...component,
  initialState: () => Anonymous,
  reducer: (action, _state) =>
    switch (action) {
    | Token(str) => ReasonReact.Update(Loaded(str))
    },
  didMount: self =>
    Js.Promise.(
      AsyncStorage.getItem("cc_token", ())
      |> then_(token =>
           (
             switch (token) {
             | None => ()
             | Some(t) => self.send(Token(t))
             }
           )
           |> resolve
         )
      |> ignore
    ),
  render: self =>
    <View>
      <Helmet title="Coolcast" meta />
      {
        switch (self.state) {
        | Anonymous => <Layout> ...children </Layout>
        | Loaded(_) =>
          <GetUserQuery variables=userQuery##variables>
            ...(
                 ({result}) =>
                   switch (result) {
                   | Loading => <Layout> ...children </Layout>
                   | Data(response) =>
                     switch (response##me) {
                     | Some(me) =>
                       <UserContext.Provider
                         value={id: me##id, email: me##email}>
                         <Layout user={id: me##id, email: me##email}>
                           ...children
                         </Layout>
                       </UserContext.Provider>
                     | None => ReasonReact.null
                     }
                   | Error(error) =>
                     <div> {ReasonReact.string(error##message)} </div>
                   }
               )
          </GetUserQuery>
        }
      }
    </View>,
};