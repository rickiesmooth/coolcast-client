open BsReactNative;
open GatsbyLink;
open GlobalStyles;

type action =
  | Email(string)
  | Password(string)
  | Name(string);

type state = {
  password: string,
  email: string,
  name: string,
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
  initialState: () => {email: "", password: "", name: ""},
  reducer: action =>
    switch (action) {
    | Password(pw) => (state => ReasonReact.Update({...state, password: pw}))
    | Email(email) => (state => ReasonReact.Update({...state, email}))
    | Name(name) => (state => ReasonReact.Update({...state, name}))
    },
  render: self =>
    <View style=GlobalStyles.Styles.containerSmall>
      <Text value="Signup to CoolCast" />
      <TextInput
        placeholder="name"
        onChangeText={text => self.send(Name(text))}
        style=Styles.inputDefault
      />
      <TextInput
        placeholder="email"
        onChangeText={text => self.send(Email(text))}
        style=Styles.inputDefault
      />
      <TextInput
        placeholder="password"
        onChangeText={text => self.send(Password(text))}
        style=Styles.inputDefault
        secureTextEntry=true
      />
      <CreateUserMutation>
        ...{
             (mutate, {result}) =>
               switch (result) {
               | NotCalled =>
                 <Button
                   title="Login"
                   onPress=(
                     _ => {
                       let mutation =
                         CreateUser.make(
                           ~name=self.state.name,
                           ~email=self.state.email,
                           ~password=self.state.password,
                           (),
                         );
                       mutate(~variables=mutation##variables, ()) |> ignore;
                     }
                   )
                 />
               | Loading => <Text value="loading" />
               | Data(res) =>
                 ignore(
                   AsyncStorage.setItem("cc_token", res##signup##token, ()),
                 );
                 <GatsbyRedirect to_="/" noThrow=true />;
               | Error(_) => <Text value="Error" />
               }
           }
      </CreateUserMutation>
    </View>,
};