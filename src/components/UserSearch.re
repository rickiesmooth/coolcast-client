open BsReactNative;

let component = ReasonReact.statelessComponent("UserSearch");

module GetAllRecipitants = [%graphql
  {|
   query getUsers($query: String!){
       searchUser(string: $query) {
           name
           email
       }
   }
 |}
];

module GetRecipitantsListQuery = ReasonApollo.CreateQuery(GetAllRecipitants);

let myKeyExtractor = (_item, index) => string_of_int(index);
let renderMyItem =
  FlatList.renderItem(user =>
    switch (user.item) {
    | Some(user) =>
      <View> <Text value=user##name /> <Text value=user##email /> </View>
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
                   keyExtractor=myKeyExtractor
                   renderItem=renderMyItem
                 />
               | None => <Text value="user not found" />
               }
             }
         }
    </GetRecipitantsListQuery>;
  },
};