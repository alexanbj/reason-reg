module Styles = {
  open Css;

  let h1 = style([textAlign(center)]);

  let img =
    style([
      display(block),
      margin2(px(30), auto),
      unsafe("width", "50%"),
    ]);
};

let component = ReasonReact.statelessComponent("SignedOut");

let make = _children => {
  ...component,
  render: _self =>
    <Container>
      <h1 className=Styles.h1> {ReasonReact.string("See ya later")} </h1>
      <img className=Styles.img src="/undraw_airport_2581.svg" />
    </Container>,
};