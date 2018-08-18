module GetVacationDays = [%graphql
  {|
  query getVacationDays {
      balance {
          vacation
      }
  }
|}
];

module GetVacationDaysQuery = ReasonApollo.CreateQuery(GetVacationDays);

let component = ReasonReact.statelessComponent("Vacation");

let make = _children => {
  ...component,
  render: _self =>
    <GetVacationDaysQuery>
      ...{
           ({result}) =>
             switch (result) {
             | Loading => <div> {ReasonReact.string("Loading")} </div>
             | Error(error) =>
               <div> {ReasonReact.string(error##message)} </div>
             | Data(response) =>
               <div>
                 {
                   ReasonReact.string(
                     "Feriedager: "
                     ++ string_of_int(response##balance##vacation),
                   )
                 }
               </div>
             }
         }
    </GetVacationDaysQuery>,
};