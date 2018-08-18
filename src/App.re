/* Our different routes */
type route =
  | Home
  | SignedOut
  | NotFound;

type state = {route};

type action =
  | ChangeRoute(route);

let reducer = (action, _state) =>
  switch (action) {
  | ChangeRoute(route) => ReasonReact.Update({route: route})
  };

let mapUrlToRoute = (url: ReasonReact.Router.url) =>
  switch (url.path) {
  | [] => Home
  | ["signed-out"] => SignedOut
  | _ => NotFound
  };

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  reducer,
  initialState: () => {route: Home},
  render: self =>
    <Fragment>
      <Header />
      <main>
        {
          switch (self.state.route) {
          | Home => <TimesheetPage />
          | SignedOut => <SignedOut />
          | NotFound => <NotFound />
          }
        }
      </main>
      <Footer />
    </Fragment>,
};