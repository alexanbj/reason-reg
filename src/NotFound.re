let component = ReasonReact.statelessComponent("NotFound");

let make = _children => {
  ...component,
  render: _self =>
    <div>
      {ReasonReact.string("The page you are looking for was not found")}
    </div>,
};