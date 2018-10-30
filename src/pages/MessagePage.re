open BsReactNative;
open GatsbyLink;

let component = ReasonReact.statelessComponent("profile");

let text = ReasonReact.string;

let make = _children => {
  ...component,
  render: _self =>
    <Shell>
      <View style=GlobalStyles.Styles.containerSmall>
        <Text value="Messages page" />
        <MessageNew />
      </View>
    </Shell>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
/*

 open BsReactNative;
 open GatsbyLink;
 open GlobalStyles;

 let component = ReasonReact.statelessComponent("messages");

 module GetAllRecipitants = [%graphql
   {|
   query getUsers($query: String!){
       searchUser(string: $query) {
           name
       }
   }
 |}
 ];

 module GetRecipitantsListQuery = ReasonApollo.CreateQuery(GetAllRecipitants);

 let make = _children => {
   ...component,
   render: _self =>
     <Shell>
       <View style=GlobalStyles.Styles.containerDefault>
         <Text value="Message page" />
         <TextInput
           placeholder="type name"
           onChangeText={
             e => {
               Js.log(e);
               ();
             }
           }
         />
       </View>
     </Shell>,
   /* <GetRecipitantsListQuery>
        ...{
             ({result, fetchMore}) =>
               switch (result) {
               | Loading => <div> {"Loading" |> ReasonReact.string} </div>
               | Error(_e) => <div> {"Error" |> ReasonReact.string} </div>
               | Data(response) =>
                 <View>
                   <TextInput
                     placeholder="type a name"
                     onChangeText=(
                       _e =>
                         fetchMore(
                           ~updateQuery=
                             (prev, _next) =>
                               /* Update Apollo Store with [@bs.raw {||}] for now, since the type comming in is a generic Js.Json.t for now*/
                               prev,
                           (),
                         )
                         |> ignore
                     )
                   />
                 </View>
               /* <User user=response##id /> */
               }
           }
      </GetRecipitantsListQuery> */
 };

 let default =
   ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children)); */