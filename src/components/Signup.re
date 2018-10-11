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

let component = ReasonReact.reducerComponent("Signup");

module CreateUser = [%graphql
  {|
  mutation createUser($name: String! $email: String!, $password: String!) {
      signup(name: $name, email: $email, password: $password) {
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
    <View style=GlobalStyles.Styles.containerSmall>
      <Text value="Signup to CoolCast" />
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
                   ~name="Bob",
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
                   AsyncStorage.setItem("cc_token", res##signup##token, ()),
                 );
                 <GatsbyRedirect to_="/" noThrow=true />;
               | Error(_) => <Text value="Error" />
               };
             }
           }
      </CreateUserMutation>
    </View>,
};