open Cmdliner
open {{ project_slug | modulify }}

let run ~nameToGreet =
  let greeting = Utils.greet nameToGreet in
  Console.log @@ Pastel.createElement ~children:[ greeting ] ();
  Lwt.return ()

let cmd =
  let doc = "Print a hello world message" in
  let nameToGreet =
    let open Arg in
    let doc = "The person to greet." in
    required & pos 0 (some string) None & info [] ~docv:"NAME" ~doc
  in
  let runCommand nameToGreet = Lwt_main.run (run ~nameToGreet) in
  let open Term in
  ( const runCommand $ nameToGreet
  , info
      "hello"
      ~doc
      ~envs:Man.envs
      ~version:Man.version
      ~exits:Man.exits
      ~man:Man.man
      ~sdocs:Man.sdocs )
