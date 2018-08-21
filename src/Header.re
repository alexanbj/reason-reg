module Styles = {
  open Css;

  let header = style([padding(px(30))]);

  let divider =
    style([
      verticalAlign(middle),
      marginLeft(rem(0.5)),
      marginRight(rem(0.5)),
      borderLeftWidth(px(1)),
      borderLeftStyle(solid),
      borderColor(Theme.shadedColor),
    ]);

  let rightAlign = style([display(flexBox), justifyContent(flexEnd)]);
};

let component = ReasonReact.statelessComponent("Header");

let make = (~authenticationStatus, _children) => {
  ...component,
  render: _self =>
    <header className=Styles.header>
      <Container>
        <div className=Styles.rightAlign>
          {
            switch (authenticationStatus) {
            | App.Authenticated =>
              <>
                <DisplayUserName />
                <span className=Styles.divider />
                <Link route=Route.SignedOut>
                  {ReasonReact.string("Logg ut")}
                </Link>
              </>
            | App.Unauthenticated =>
              <Link route=Route.Auth> {ReasonReact.string("Logg inn")} </Link>
            }
          }
        </div>
      </Container>
    </header>,
};