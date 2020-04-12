open Cmdliner;

let defaultCmd = {
  let doc = "{{ project_description }}";

  (
    Term.(ret(const(_ => `Help((`Pager, None))) $ const())),
    Term.info(
      "{{ project_slug }}",
      ~doc,
      ~envs=Man.envs,
      ~version=Man.version,
      ~exits=Man.exits,
      ~man=Man.man,
      ~sdocs=Man.sdocs,
    ),
  );
};

let argv =
  Array.map(Sys.argv, ~f=arg =>
    switch (arg) {
    | "-v" => "--version"
    | x => x
    }
  );

let _ = Term.exit @@ Term.eval_choice(defaultCmd, Commands.all, ~argv);
