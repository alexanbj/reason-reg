let component = ReasonReact.statelessComponent("SignedOut");

let make = _children => {
  ...component,
  render: _self =>
    <div>
      (ReasonReact.string("See ya later"))
    </div>,
};