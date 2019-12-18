open {{ project_slug | camel_case }};

let user:
  Graphql_lwt.Schema.typ(Hmap.t, option({{ project_slug | camel_case }}.Accounts_user.t)) =
  Graphql_lwt.Schema.(
    obj("user", ~doc="A user in the system", ~fields=_ =>
      [
        field(
          "id",
          ~typ=non_null(int),
          ~args=Arg.[],
          ~resolve=(info, p: Accounts_user.t) =>
          p.id
        ),
        field(
          "name",
          ~typ=non_null(string),
          ~args=Arg.[],
          ~resolve=(info, p: Accounts_user.t) =>
          p.name
        ),
      ]
    )
  );

let queries =
  Graphql_lwt.Schema.[
    io_field(
      "users",
      ~typ=non_null(list(non_null(user))),
      ~args=Arg.[],
      ~resolve=Resolver__Accounts.users,
    ),
  ];

let mutations = [];
