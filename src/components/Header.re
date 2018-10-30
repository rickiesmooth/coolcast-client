open BsReactNative;
open Context;

let component = ReasonReact.statelessComponent("Header");

let styles =
  StyleSheet.create(
    Style.{
      "head": style([color(String("#f58c93"))]),
      "wrapper":
        style([
          flexDirection(Row),
          maxWidth(Pt(960.)),
          width(Pct(100.0)),
        ]),
      "right": style([flexDirection(Row), marginLeft(Auto)]),
      "profile": style([flexDirection(Row)]),
      "header":
        style([
          backgroundColor(String("#000")),
          /* position(Absolute),
             bottom(Pt(0.)), */
          width(Pct(100.0)),
          alignItems(Center),
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
        <GatsbyLink to_="/">
          <Text style=styles##head value=siteTitle />
        </GatsbyLink>
        <View style=styles##right>
          {
            switch (user) {
            | Some(u) =>
              <View style=styles##profile>
                <GatsbyLink to_="/messages">
                  <Text value="messages" style=styles##head />
                </GatsbyLink>
                <GatsbyLink to_="/profile">
                  <Text value={u.email} style=styles##head />
                </GatsbyLink>
              </View>
            | None =>
              <GatsbyLink to_="/login">
                <Text style=styles##head value="Login" />
              </GatsbyLink>
            }
          }
        </View>
      </View>
    </View>,
};