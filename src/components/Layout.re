open BsReactNative;
open Belt;
open Context;

let component = ReasonReact.statelessComponent("Layout");

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
  render: _self =>
    <View>
      <Helmet title="Coolcast" meta />
      <GetUserQuery variables=userQuery##variables>
        ...{
             ({result}) =>
               switch (result) {
               | Loading => <Header siteTitle="CoolCast" />
               | Data(response) =>
                 switch (response##me) {
                 | Some(me) =>
                   <UserContext.Provider value=me##email>
                     <Header siteTitle="CoolCast" />
                     <View> ...children </View>
                   </UserContext.Provider>
                 | None => <View />
                 }
               | Error(error) =>
                 <div> {ReasonReact.string(error##message)} </div>
               }
           }
      </GetUserQuery>
    </View>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));