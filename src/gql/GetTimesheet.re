type workSchedule = {
  normalHours: float,
  date: Js.Json.t,
  publicHoliday: bool,
  workingDay: bool,
};

type project = {
  id: string,
  description: string,
};

type workOrder = {description: string};

type detail = {
  id: string,
  description: string,
  project,
  workOrder,
  values: Js.Array.t(float),
  sum: float,
};

type currentSheet = {
  workSchedule: Js.Array.t(workSchedule),
  details: Js.Array.t(detail),
};

module GetTimesheetGql = [%graphql
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

module GetTimesheetQuery = ReasonApollo.CreateQuery(GetTimesheetGql);