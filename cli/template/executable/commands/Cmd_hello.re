open Cmdliner;
open {{ project_slug | camel_case }};

let run = (~nameToGreet) => {
  let greeting = Utils.greet(nameToGreet);
  Console.log(<Pastel> greeting </Pastel>);
  Lwt.return();
};

let cmd = {
  let doc = "Print a hello world message";

  let nameToGreet = {
    let doc = "The person to greet.";
    Arg.(required & pos(0, some(string), None) & info([], ~docv="NAME", ~doc));
  };

  let runCommand = nameToGreet => Lwt_main.run(run(~nameToGreet));

  (
    Term.(const(runCommand) $ nameToGreet),
    Term.info(
      "hello",
      ~doc,
      ~envs=Man.envs,
      ~version=Man.version,
      ~exits=Man.exits,
      ~man=Man.man,
      ~sdocs=Man.sdocs,
    ),
  );
};