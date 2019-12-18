exception MissingEnvVar(string);

let handleErrors = fn =>
  try(fn()) {
  | MissingEnvVar(name) =>
    Console.error(
      <Pastel color=Pastel.Red>
        {"😱  Ooops, it seems you don't have an environment variable named \""
         ++ name
         ++ "\". I need it to work!"}
      </Pastel>,
    );
    Caml.exit(201);
  
  | _ as exn =>
    Console.log(
      <Pastel color=Pastel.Red>
        {"😱  Ooops, an unknown error occured. You can file a bug reports at https://github.com/tmattio/{{ project_slug }}.\n"
         ++ "Here is the stack trace in case it helps:\n"}
      </Pastel>,
    );

    raise(exn);
  };

type error = {
  doc: string,
  exit_code: int,
};

let all = () => [
  {doc: "on missing required environment variable.", exit_code: 201},
  {doc: "on other exceptions.", exit_code: 299},
];
