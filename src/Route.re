type route =
  | Home
  | Auth
  | SignedOut
  | NotFound;

let routeToUrl = route =>
  switch (route) {
  | Home => "/"
  | Auth => "/auth"
  | SignedOut => "signed-out"
  | NotFound =>
    raise(
      Invalid_argument("You're trying to navigate to a not found route"),
    )
  };

let urlToRoute = (url: ReasonReact.Router.url) =>
  switch (url.path) {
  | [] => Home
  | ["auth"] => Auth
  | ["signed-out"] => SignedOut
  | _ => NotFound
  };