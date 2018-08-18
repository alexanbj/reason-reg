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
            <a href="https://reasonml.github.io/">
              {ReasonReact.string("Reason")}
            </a>
            {ReasonReact.string(" & ")}
            <a href="https://graphql.org/">
              {ReasonReact.string("GraphQL.")}
            </a>
          </small>
        </p>
        <p> <small> {ReasonReact.string("Made by alb.")} </small> </p>
      </Container>
    </footer>,
};