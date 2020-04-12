type variable_doc('t) = {
  name: string,
  doc: string,
  default: string,
};

module EnvVar =
       (
         M: {
           type t;
           let name: string;
           let doc: string;
           let default: t;
           let parse: string => t;
           let unparse: t => string;
         },
       ) => {
  include M;
  let opt_value = Sys.getenv_opt(name) |> Option.map(parse);
  let get_opt = () => opt_value;
  let get = () => get_opt() |> Option.value(~default);
  let doc_info = {name, doc, default: unparse(default)};
};

let getenv_exn = name => {
  let fn = () => {
    switch (Sys.getenv_opt(name)) {
    | Some(env) => env
    | _ => raise(Errors.Missing_env_var(name))
    };
  };
  Errors.handle_errors(fn);
};

module {{ project_slug | snake_case | upper }}_CACHE_DIR =
  EnvVar({
    type t = string;
    let parse = Utils.Filename.ensure_trailing;
    let unparse = Utils.Filename.ensure_trailing;
    let name = "{{ project_slug | snake_case | upper }}_CACHE_DIR";
    let doc = "The directory where the cached data is stored.";
    let default = {
      let home =
        switch (Sys.os_type) {
        | "Unix" => getenv_exn("HOME")
        | _ => getenv_exn("APPDATA")
        };
      let cache_dir = Filename.concat(home, ".cache");
      Filename.concat(cache_dir, "{{ project_slug }}");
    };
  });

let all = () => [{{ project_slug | snake_case | upper }}_CACHE_DIR.doc_info];
