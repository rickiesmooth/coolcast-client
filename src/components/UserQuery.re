open BsReactNative;
open GatsbyLink;

let component = ReasonReact.statelessComponent("UserQuery");

module GetAllRecipitants = [%graphql
  {|
   query getUsers($query: String!){
       searchUser(string: $query) {
           name
           email
           id
           chats {
             id
           }
       }
   }
 |}
];

module GetRecipitantsListQuery = ReasonApollo.CreateQuery(GetAllRecipitants);

let renderUserItem =
  FlatList.renderItem(user =>
    switch (user.item) {
    | Some(user) =>
      <TouchableWithoutFeedback
        onPress=(_ => ReasonReact.Router.push("/messages/new/?" ++ user##id))>
        <View> <Text value=user##name /> <Text value=user##email /> </View>
      </TouchableWithoutFeedback>
    | None => <Text value="user not found" />
    }
  );

let make = (~query, _children) => {
  ...component,
  render: _self => {
    let getUsersQuery = GetAllRecipitants.make(~query, ());
    <GetRecipitantsListQuery variables=getUsersQuery##variables>
      ...{
           ({result}) =>
             switch (result) {
             | Loading => <Text value="loading" />
             | Error(_e) => <Text value="Error" />
             | Data(response) =>
               switch (response##searchUser) {
               | Some(users) =>
                 <FlatList
                   data=users
                   keyExtractor=((_item, index) => string_of_int(index))
                   renderItem=renderUserItem
                 />
               | None => <Text value="user not found" />
               }
             }
         }
    </GetRecipitantsListQuery>;
  },
};