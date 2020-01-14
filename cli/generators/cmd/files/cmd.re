open Cmdliner;
open {{ project_slug | modulify }};

let run = () => {
  Console.log("Hello World!");
  Lwt.return();
};

let cmd = {
  let doc = "Prints a hello world message to the standard output.";

  let run_command = () => run |> Errors.handle_errors |> Lwt_main.run;

  (
    Term.(app(const(run_command), const())),
    Term.info(
      "{{ cmd_name | slugify }}",
      ~doc,
      ~envs=Man.envs,
      ~version=Man.version,
      ~exits=Man.exits,
      ~man=Man.man,
      ~sdocs=Man.sdocs,
    ),
  );
};
