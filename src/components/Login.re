open BsReactNative;
open GatsbyLink;

type action =
  | Email(string)
  | Password(string);

type state = {
  password: string,
  email: string,
};

let ste = ReasonReact.string;

let component = ReasonReact.reducerComponent("Login");

/* mutation {
     login(email: "alice@prisma.io", password: "graphql") {
       token
     }
   } */

module CreateUser = [%graphql
  {|
  mutation loginUser($email: String!, $password: String!) {
      login( email: $email, password: $password) {
          token
      }
  }
|}
];

module CreateUserMutation = ReasonApollo.CreateMutation(CreateUser);

let make = _children => {
  ...component,
  initialState: () => {email: "", password: ""},
  reducer: action =>
    switch (action) {
    | Password(pw) => (state => ReasonReact.Update({...state, password: pw}))
    | Email(email) => (state => ReasonReact.Update({...state, email}))
    },
  render: self =>
    <View>
      <Text value="Login to CoolCast" />
      <TextInput
        placeholder="email"
        onChangeText={text => self.send(Email(text))}
      />
      <TextInput
        placeholder="password"
        onChangeText={text => self.send(Password(text))}
      />
      <CreateUserMutation>
        ...{
             (mutate, {result}) => {
               let mutation =
                 CreateUser.make(
                   ~email=self.state.email,
                   ~password=self.state.password,
                   (),
                 );
               switch (result) {
               | NotCalled =>
                 <Button
                   title="Login"
                   onPress=(
                     _ => mutate(~variables=mutation##variables, ()) |> ignore
                   )
                 />
               | Loading => <Text value="loading" />
               | Data(res) =>
                 ignore(
                   AsyncStorage.setItem("cc_token", res##login##token, ()),
                 );
                 <GatsbyRedirect to_="/" noThrow=true />;
               | Error(_res) => <Text value="Error" />
               };
             }
           }
      </CreateUserMutation>
      <GatsbyLink to_="/signup"> <Text value="Or signup" /> </GatsbyLink>
    </View>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));