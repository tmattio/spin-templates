open {{ project_slug | camel_case }};

let users =
    (_info, ())
    : Lwt.t(Result.t(list(Accounts_user.t), Graphql_lwt.Schema.field_error)) => {
  let users = Accounts.getAllUsers();
  Lwt_result.lift(users);
};
