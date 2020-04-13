[@bs.deriving abstract]
type _route = {
  key: string,
  [@bs.optional]
  title: string,
  [@bs.optional] [@bs.as "icon"]
  iconAsRenderFunc: Icon.renderIcon,
  [@bs.optional]
  color: string,
  [@bs.optional]
  accessibilityLabel: string,
  [@bs.optional]
  testID: string,
};

let route =
    (~key, ~title=?, ~icon=?, ~color=?, ~accessibilityLabel=?, ~testID=?, ()) =>
  switch (icon) {
  | Some(Icon.Name(name)) =>
    _route(
      ~key,
      ~title?,
      ~color?,
      ~accessibilityLabel?,
      ~testID?,
      (),
    )
  | Some(Icon.Element(renderFunc)) =>
    _route(
      ~key,
      ~title?,
      ~iconAsRenderFunc=renderFunc,
      ~color?,
      ~accessibilityLabel?,
      ~testID?,
      (),
    )
  | None => _route(~key, ~title?, ~color?, ~accessibilityLabel?, ~testID?, ())
  };

[@bs.deriving abstract]
type createNavigationState = {
  index: int,
  routes: array(_route),
};

type renderIconType = {
  route: _route,
  focused: bool,
  color: string,
};

type routeType = {route: _route};

type routeProps = {
  key: string,
  title: string,
  color: string,
};

type jsRenderSceneProps = {
  .
  "route": routeProps,
  "jumpTo": string => unit,
};

type renderSceneProps = {
  route: routeProps,
  jumpTo: string => unit,
};

type renderSceneType = jsRenderSceneProps => React.element;

let renderSceneType =
    (reRenderScene: renderSceneProps => React.element): renderSceneType =>
  (jsRouteProps: jsRenderSceneProps) =>
    reRenderScene({route: jsRouteProps##route, jumpTo: jsRouteProps##jumpTo});

[@bs.module "react-native-paper"] [@react.component]
external make:
  (
    ~shifting: bool=?,
    ~labeled: bool=?,
    ~navigationState: createNavigationState,
    ~onIndexChange: int => unit,
    ~renderScene: renderSceneType,
    ~getLabelText: routeType => string=?,
    ~getAccessibilityLabel: routeType => string=?,
    ~getColor: routeType => string=?,
    ~onTabPress: routeType => string=?,
    ~activeColor: string=?,
    ~inactiveColor: string=?,
    ~barStyle: ReactNative.Style.t=?,
    ~getTestID: routeType => string=?,
    ~renderIcon: renderIconType => React.element=?,
    ~style: ReactNative.Style.t=?,
    ~theme: Paper_ThemeProvider.appTheme=?,
    ~children: React.element=?
  ) =>
  React.element =
  "BottomNavigation";