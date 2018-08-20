open Route;

type state = {route};

type action =
  | ChangeRoute(route);

let reducer = (action, _state) =>
  switch (action) {
  | ChangeRoute(route) => ReasonReact.Update({route: route})
  };

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  reducer,
  initialState: () => {
    route: ReasonReact.Router.dangerouslyGetInitialUrl()->Route.urlToRoute,
  },
  render: self =>
    <>
      <Header />
      <main>
        {
          switch (self.state.route) {
          | Home => <TimesheetPage />
          | SignedOut => <SignedOut />
          | Auth => <Auth />
          | NotFound => <NotFound />
          }
        }
      </main>
      <Footer />
    </>,
};