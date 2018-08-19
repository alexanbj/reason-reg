module Styles = {
  open Css;

  let a =
    style([
      textDecoration(none),
      color(Theme.secondaryColor),
      transition(~duration=15, ~timingFunction=easeIn, "opacity"),
      hover([opacity(0.5)]),
    ]);
};

let component = ReasonReact.statelessComponent("Link");

let make = (~onClick, children) => {
  ...component,
  render: _self => <a className=Styles.a onClick> ...children </a>,
};