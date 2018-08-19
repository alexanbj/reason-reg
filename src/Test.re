module GetVacationDays = [%graphql
  {|
  query getVacationDays {
      balance {
          vacation
          flex
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
             | Loading => ReasonReact.null
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
                 {
                   ReasonReact.string(
                     "Flex: "
                     ++ string_of_float(response##balance##flex),
                   )
                 }
               </div>
             }
         }
    </GetVacationDaysQuery>,
};