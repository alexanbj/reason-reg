module Styles = {
  open Css;

  let detailsRow = style([hover([backgroundColor(Theme.shadedColor)])]);
};

let component = ReasonReact.statelessComponent("Rows");

let make = (_children, ~timesheet) => {
  ...component,
  render: _self =>
    timesheet##details
    |> Js.Array.map(detail =>
         <tr key=detail##id className=Styles.detailsRow>
           <td> {ReasonReact.string(detail##workOrder##description)} </td>
           <td> {ReasonReact.string(detail##description)} </td>
           <td> {ReasonReact.string(string_of_float(detail##sum))} </td>
          <Fragment>
            {
              detail##values
              |> Js.Array.map(value =>
                   <td>
                     {ReasonReact.string(string_of_float(value))}
                   </td>
                 )
            }
          </Fragment>
         </tr>
       )
    |> ReasonReact.array,
};