Fmt_tty.setup_std_outputs();
Logs.set_level(Some(Logs.Info));
Logs.set_reporter(Logs_fmt.reporter());

let graphql_handler =
  Morph_graphql_server.make({{ project_slug | camel_case }}Web.Schema.schema);

let handler = (request: Morph.Request.t) => {
  open Morph;

  let path_parts =
    request.target
    |> Uri.of_string
    |> Uri.path
    |> String.split_on_chars(~on=['/'])
    |> List.filter(~f=s => !String.equal(s, ""));

  switch (request.meth, path_parts) {
  | (`GET, ["api"]) =>
    Morph.Response.text({{ project_slug | camel_case }}Web.GraphiQL.html, Morph.Response.empty)
  | (_, ["api"]) => graphql_handler(request)
  | (_, _) => Response.not_found(Response.empty)
  };
};

let http_server = Morph_server_http.make();

Morph.start(
  ~servers=[http_server],
  ~middlewares=[{{ project_slug | camel_case }}Web.Middleware.logger],
  handler,
)
|> Lwt_main.run;
