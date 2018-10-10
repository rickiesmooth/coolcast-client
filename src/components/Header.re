open BsReactNative;
open Context;

let component = ReasonReact.statelessComponent("Header");

let styles =
  StyleSheet.create(
    Style.{
      "head": style([color(String("#ggg")), fontSize(Float(32.))]),
      "wrapper":
        style([
          flexDirection(Row),
          maxWidth(Pt(960.)),
          marginBottom(Pt(0.)),
        ]),
      "profile":
        style([
          display(Flex),
          justifyContent(Center),
          flexDirection(Column),
          marginLeft(Auto),
        ]),
      "header":
        style([
          backgroundColor(String("#eee")),
          paddingVertical(Pt(8.)),
          paddingHorizontal(Pt(16.)),
        ]),
    },
  );

let make = (~siteTitle: string, ~user, _children) => {
  ...component,
  render: _self =>
    <View style=styles##header>
      <View style=styles##wrapper>
        <Text style=styles##head value=siteTitle />
        <View style=styles##profile>
          {
            switch (user) {
            | Some(u) => <Text value={u.email} />
            | None =>
              <GatsbyLink to_="/login">
                {ReasonReact.string("Login")}
              </GatsbyLink>
            }
          }
        </View>
      </View>
    </View>,
};