module GetCurrentUser = [%graphql
  {|
  query getCurrentUser {
      currentUser {
        id
        userName
      }
  }
|}
];

module GetCurrentUserQuery = ReasonApollo.CreateQuery(GetCurrentUser);

let component = ReasonReact.statelessComponent("DisplayUserName");

let make = _children => {
  ...component,
  render: _self =>
    <GetCurrentUserQuery>
      ...{
           ({result}) =>
             switch (result) {
             | Loading => ReasonReact.null
             | Error(_error) => ReasonReact.null
             | Data(response) =>
               ReasonReact.string(response##currentUser##userName)
             }
         }
    </GetCurrentUserQuery>,
};