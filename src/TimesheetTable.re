module Styles = {
  open Css;

  /* ffs... Why wont it lt me use with in a typesafe way.. */
  let table =
    style([
      fontSize(rem(0.75)),
      unsafe("border-collapse", "collapse"),
      width(pct(100.)),
    ]);

  let notWorkDay = style([backgroundColor(green)]);
};

let component = ReasonReact.statelessComponent("TimesheetTable");

let make = (~timesheet, _children) => {
  ...component,
  render: _self =>
    <table className=Styles.table>
      <thead>
        <tr>
          <th> {ReasonReact.string("Arbeidsoppgave")} </th>
          <th> {ReasonReact.string("Beskrivelse")} </th>
          <th> {ReasonReact.string("Sum")} </th>
          <>
            {
              timesheet##workSchedule
              |> Js.Array.map(ws =>
                   <th>
                     <div>
                       {
                         ReasonReact.string(
                           DateTimeFormat.shortWeekDay(ws##date),
                         )
                       }
                     </div>
                     <div>
                       {ReasonReact.string(DateTimeFormat.day(ws##date))}
                     </div>
                   </th>
                 )
              |> ReasonReact.array
            }
          </>
        </tr>
        <tr>
          <th />
          <th scope="row"> {ReasonReact.string("Normaltid")} </th>
          <th />
          <>
            {
              timesheet##workSchedule
              |> Js.Array.map(ws =>
                   <th>
                     {ReasonReact.string(string_of_float(ws##normalHours))}
                   </th>
                 )
              |> ReasonReact.array
            }
          </>
        </tr>
      </thead>
      <tbody> <Rows timesheet /> </tbody>
    </table>,
};