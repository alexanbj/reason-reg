module Styles = {
  open Css;
  
  let table = style([fontSize(rem(0.75))]);

  let notWorkDay = style([backgroundColor(green)]);
};

let component = ReasonReact.statelessComponent("Timesheet");

let make = (_children, ~timesheet) => {
  ...component,
  render: _self =>
    <table className=Styles.table>
      <thead>
        <tr>
          <th> {ReasonReact.string("Arbeidsoppgave")} </th>
          <th> {ReasonReact.string("Beskrivelse")} </th>
          <th> {ReasonReact.string("Sum")} </th>
          <Fragment>
            {
              timesheet##workSchedule
              |> Js.Array.map(ws =>
                   switch (ws##workingDay, ws##publicHoliday) {
                   | (_, true) =>
                     <th> {ReasonReact.string("Holiday")} </th>
                   | (true, _) =>
                     <th> {ReasonReact.string("Working day")} </th>
                   | (false, false) =>
                     <th> {ReasonReact.string("regular day")} </th>
                   }
                 )
            }
          </Fragment>
        </tr>
        <tr>
          <th />
          <th scope="row"> {ReasonReact.string("Normaltid")} </th>
          <th />
          <Fragment>
            {
              timesheet##workSchedule
              |> Js.Array.map(ws =>
                   <th>
                     {ReasonReact.string(string_of_float(ws##normalHours))}
                   </th>
                 )
            }
          </Fragment>
        </tr>
      </thead>
      <tbody> <Rows timesheet /> </tbody>
    </table>,
};