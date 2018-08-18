module Styles = {
  open Css;

  let container = style([maxWidth(px(980)), marginLeft(auto), marginRight(auto)]);
};

let component = ReasonReact.statelessComponent("Footer");

let make = children => {
  ...component,
  render: _self => <div className={Styles.container}> ...children </div>,
};