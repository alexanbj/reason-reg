module Styles = {
  open Css;

  let footer =
    style([padding(px(30))]);
};

let component = ReasonReact.statelessComponent("Footer");

let make = _children => {
  ...component,
  render: _self =>
    <footer className=Styles.footer>
      <Container>
        <p>
          <small>
            {ReasonReact.string("Powered by ")}
            <A href="https://reasonml.github.io/">
              {ReasonReact.string("Reason")}
            </A>
            {ReasonReact.string(" & ")}
            <A href="https://graphql.org/">
              {ReasonReact.string("GraphQL.")}
            </A>
          </small>
        </p>
        <p> <small> {ReasonReact.string("Made by alb.")} </small> </p>
      </Container>
    </footer>,
};