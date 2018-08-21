let component = ReasonReact.statelessComponent("Link");

let handleClick = (href, onClick, event) => {
  /** TODO: Figure out if this the way to handle options */
  (
    switch (onClick) {
    | Some(onClick) => event->onClick
    | _ => ()
    }
  );

  /** TODO: Only do this if the default hasn't been prevented? */
  event->ReactEvent.Mouse.preventDefault;
  ReasonReact.Router.push(href);
};

let make = (~route: Route.route, ~onClick=?, children) => {
  ...component,
  render: _self => {
    let href = Route.routeToUrl(route);
    <A href onClick={handleClick(href, onClick)}> ...children </A>;
  },
};