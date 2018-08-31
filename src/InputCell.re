module Styles = {
  open Css;

  let input =
    style([
      background(transparent),
      borderStyle(none),
      color(Theme.textColor),
      width(pct(100.)),
    ]);
};

let component = ReasonReact.statelessComponent("InputCell");

let make = (~defaultValue, _children) => {
  ...component,
  render: _self => <input className=Styles.input type_="text" defaultValue />,
};