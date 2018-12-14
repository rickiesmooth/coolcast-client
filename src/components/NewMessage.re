open BsReactNative;
open GatsbyLink;

let component = ReasonReact.statelessComponent("NewMessageQuery");

module GetUserChat = [%graphql
  {|
   query getChat($userId: String!){
       chat(userId: $userId) {
             id
      }
   }
 |}
];

module GetUserChatQuery = ReasonApollo.CreateQuery(GetUserChat);

let make = (~userId, _children) => {
  ...component,
  render: _self => {
    let getUserChatQuery = GetUserChat.make(~userId, ());
    <GetUserChatQuery variables=getUserChatQuery##variables>
      ...{
           ({result}) =>
             switch (result) {
             | Loading => <Text value="loading" />
             | Error(_e) => <Text value="Error" />
             | Data(response) =>
               switch (response##chat) {
               | Some(chat) =>
                 <GatsbyRedirect to_={"/messages/" ++ chat##id} noThrow=true />
               | None => <TextInput placeholder="user not found" />
               }
             }
         }
    </GetUserChatQuery>;
  },
};