let component = ReasonReact.statelessComponent("SafeLink");

let make = (~route: Route.route, children) => {
  ...component,
  render: _self => {
    let href = Route.routeToUrl(route);
    <a href> ...children </a>;
  },
};