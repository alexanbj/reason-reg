module Styles = {
  open Css;

  let button = style([]);
};

let component = ReasonReact.statelessComponent("Button");

let make = (~onClick=?, children) => {
  ...component,
  render: _self =>
    <button className=Styles.button type_="button" ?onClick>
      ...children
    </button>,
};