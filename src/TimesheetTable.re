module Styles = {
  open Css;

  /* ffs... Why wont it lt me use with in a typesafe way.. */
  let table =
    style([
      fontSize(rem(0.75)),
      unsafe("border-collapse", "collapse"),
      unsafe("width", "100%"),
    ]);

  let notWorkDay = style([backgroundColor(green)]);
};

type state = {timesheet: GetTimesheet.GetTimesheetGql.t};
type detail;
type action =
  | UpdateDetail(detail);

let component = ReasonReact.reducerComponent("TimesheetTable");

let reducer = (action: action, state) =>
  ReasonReact.Update({timesheet: state.timesheet});

let make = (~timesheet, _children) => {
  ...component,
  reducer,
  initialState: () => timesheet,
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