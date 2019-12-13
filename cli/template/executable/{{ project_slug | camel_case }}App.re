open Cmdliner;

let commands = [Cmd__hello.cmd];

let defaultCmd = {
  let doc = "{{ project_desc }}";
  (
    Term.(ret(const(_ => `Help((`Pager, None))) $ const())),
    Term.info(
      "{{ project_slug }}",
      ~doc,
      ~envs=Man.envs,
      ~version=Man.version,
      ~exits=Man.exists,
      ~man=Man.man,
      ~sdocs=Man.sdocs,
    ),
  );
};

let argv =
  Sys.argv
  |> Array.map(arg =>
       switch (arg) {
       | "-v" => "--version"
       | x => x
       }
     );

let _ = Term.eval_choice(defaultCmd, commands, ~argv) |> Term.exit;