let component = ReasonReact.statelessComponent("Auth");

let handleSubmit = (_event, _self) => Js.log("clicked!");

let make = _children => {
  ...component,
  render: self =>
    <Container>
      <h1> {ReasonReact.string("Logg inn")} </h1>
      <form onSubmit={self.handle(handleSubmit)}>
        <input />
        <button type_="submit"> {ReasonReact.string("Logg inn")} </button>
      </form>
    </Container>,
};