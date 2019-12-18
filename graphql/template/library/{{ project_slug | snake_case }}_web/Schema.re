let schema: Graphql_lwt.Schema.schema(Hmap.t) =
  Graphql_lwt.Schema.(
    schema(
      ~mutations=List.join(Schema__Accounts.mutations),
      List.join([Schema__Accounts.queries]),
    )
  );
