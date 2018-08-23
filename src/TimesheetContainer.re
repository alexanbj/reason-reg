open GetTimesheet;

let component = ReasonReact.statelessComponent("TimesheetContainer");

let make = _children => {
  ...component,
  render: _self =>
    <GetTimesheetQuery>
      ...{
           ({result}) =>
             switch (result) {
             | Loading => <ActivityIndicator />
             | Error(error) =>
               <div> {ReasonReact.string(error##message)} </div>
             | Data(response) =>
               <>
                 <TimesheetTable timesheet=response##currentSheet />
                 <Button> {ReasonReact.string("Lagre")} </Button>
               </>
             }
         }
    </GetTimesheetQuery>,
};