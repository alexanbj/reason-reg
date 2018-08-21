open Route;

type authenticationStatus =
  | Authenticated
  | Unauthenticated;

type state = {
  route,
  authenticationStatus,
};

type action =
  | ChangeRoute(route);

let reducer = (action, state) =>
  switch (action) {
  | ChangeRoute(route) =>
    ReasonReact.Update({
      route,
      authenticationStatus: state.authenticationStatus,
    })
  };

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  reducer,
  didMount: self => {
    let watcherID =
      ReasonReact.Router.watchUrl(url =>
        self.send(ChangeRoute(url |> Route.urlToRoute))
      );

    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherID));
  },
  initialState: () => {
    route: ReasonReact.Router.dangerouslyGetInitialUrl()->Route.urlToRoute,
    authenticationStatus:
      switch (Effects.getTokenFromStorage()) {
      | Some(_) => Authenticated
      | _ => Unauthenticated
      },
  },
  render: self =>
    <>
      <Header authenticationStatus={self.state.authenticationStatus} />
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