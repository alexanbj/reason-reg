module Styles = {
  open Css;

  /* TODO: Figure out opacity */
  let a =
    style([color(Theme.secondaryColor), /*transition("opacity .15s ease-in"),*/ hover([opacity(0.5)])]);
};

let component = ReasonReact.statelessComponent("Link");

let make = (children, ~onClick) => {
  ...component,
  render: _self => <a className=Styles.a onClick> ...children </a>,
};