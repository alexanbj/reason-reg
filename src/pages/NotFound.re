module Styles = {
  open Css;

  let h1 = style([textAlign(center)]);

  let img =
    style([display(block), margin2(px(30), auto), width(pct(50.))]);
};

let component = ReasonReact.statelessComponent("NotFound");

let make = _children => {
  ...component,
  render: _self =>
    <Container>
      <h1 className=Styles.h1> {ReasonReact.string("Oops!")} </h1>
      <h2 className=Styles.h1>
        {ReasonReact.string("Ser ikke ut som vi har siden du leter etter.")}
      </h2>
      <img className=Styles.img src="/undraw_lost_bqr2.svg" />
    </Container>,
};