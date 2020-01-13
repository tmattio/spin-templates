exception Missing_env_var of string

let handle_errors fn =
  try fn () with
  | Missing_env_var name ->
    Console.error
      (Pastel.createElement
         ~color:Pastel.Red
         ~children:
           [ "\240\159\152\177  Ooops, it seems you don't have an environment \
              variable named \""
             ^ name
             ^ "\". I need it to work!"
           ]
         ());
    Caml.exit 201
  | _ as exn ->
    Console.log
      (Pastel.createElement
         ~color:Pastel.Red
         ~children:
           [ "\240\159\152\177  Ooops, an unknown error occured. You can file \
              a bug reports at https://github.com/tmattio/{{ project_slug }}.\n"
             ^ "Here is the stack trace in case it helps:\n"
           ]
         ());
    raise exn

type error =
  { doc : string
  ; exit_code : int
  }

let all () =
  [ { doc = "on missing required environment variable."; exit_code = 201 } ]
