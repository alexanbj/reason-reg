module GetTimesheet = [%graphql
  {|
  query getTimesheet {
      currentSheet {
        workSchedule {
          normalHours
          date
          publicHoliday
          workingDay
        }
        details {
            id
            project {
              id
              description
            }
            workOrder {
              id
              description
            }
            description
            values
            sum
        }
      }
  }
|}
];

module GetTimesheetQuery = ReasonApollo.CreateQuery(GetTimesheet);

let component = ReasonReact.statelessComponent("Rows");

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
                 <TimesheetTable timesheet=response##currentSheet />
               }
           }
      </GetTimesheetQuery>
};