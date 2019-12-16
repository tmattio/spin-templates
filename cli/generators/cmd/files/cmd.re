open Cmdliner;
open Spin;

let run = () => {
  Console.info("Hello World!");
  Lwt.return();
};

let cmd = {
  let doc = "Prints a hello world message to the standard output.";

  let runCommand = (template, path, useDefaults) =>
    run |> Errors.handleErrors |> Lwt_main.run;

  (
    Term.(const(runCommand)),
    Term.info(
      "{{ name | snake_case }}",
      ~doc,
      ~envs=Man.envs,
      ~version=Man.version,
      ~exits=Man.exits,
      ~man=Man.man,
      ~sdocs=Man.sdocs,
    ),
  );
};
