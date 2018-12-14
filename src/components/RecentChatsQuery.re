open BsReactNative;
open GatsbyLink;
open Belt;

let component = ReasonReact.statelessComponent("RecentChatsQuery");

module GetRecentChats = [%graphql
  {|
query getRecentChatsQuery{
    recentChats {
        id
        users {
          id
          name
        }
        messages {
            id
            text
        }
    }
}
|}
];

let renderUserItem =
  FlatList.renderItem(chat =>
    switch (chat.item) {
    | Some(chat) =>
      <TouchableWithoutFeedback
        onPress=(_ => ReasonReact.Router.push("/messages/" ++ chat##id))>
        <View> <Text value=chat##id /> </View>
      </TouchableWithoutFeedback>

    | None => <Text value="user not found" />
    }
  );

module GetRecipitantsListQuery = ReasonApollo.CreateQuery(GetRecentChats);

let make = _children => {
  ...component,
  render: _self => {
    let getRecentChatsQuery = GetRecentChats.make();
    <GetRecipitantsListQuery variables=getRecentChatsQuery##variables>
      ...{
           ({result}) =>
             switch (result) {
             | Loading => <Text value="loading" />
             | Error(_e) => <Text value="Error" />
             | Data(response) =>
               switch (response##recentChats) {
               | Some(chats) =>
                 <FlatList
                   data=chats
                   keyExtractor=((_item, index) => string_of_int(index))
                   renderItem=renderUserItem
                 />
               | None => <Text value="no chats" />
               }
             }
         }
    </GetRecipitantsListQuery>;
  },
};