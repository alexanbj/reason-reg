module Styles = {
  open Css;

  let input =
    style([
      background(transparent),
      borderStyle(none),
      color(Theme.textColor),
      unsafe("width", "100%"),
    ]);
};

let component = ReasonReact.statelessComponent("InputCell");

let make = (_children, ~defaultValue) => {
  ...component,
  render: _self =>
    <input className=Styles.input type_="text" defaultValue />,
};