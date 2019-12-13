type variableDoc('t) = {
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
  let optValue = Sys.getenv_opt(name) |> Option.map(parse);
  let getOpt = () => optValue;
  let get = () => getOpt() |> Option.value(~default);
  let docInfo = {name, doc, default: unparse(default)};
};

let ensureTrailingBackslash = str =>
  switch (str.[String.length(str) - 1]) {
  | '/' => str
  | _ => str ++ "/"
  };

let getOptionorThrow = (message, opt) =>
  switch (opt) {
  | None => failwith(message)
  | Some(x) => x
  };

module {{ project_slug| modulify }}_CACHE_DIR =
  EnvVar({
    type t = string;
    let parse = ensureTrailingBackslash;
    let unparse = ensureTrailingBackslash;
    let name = "{{ project_slug| modulify }}_CACHE_DIR";
    let doc = "The directory where the templates and other cached data is stored.";
    let default = {
      let home =
        Sys.getenv_opt("HOME")
        |> getOptionorThrow("There isn't a $HOME environment variable set.");
      let cacheDir = Filename.concat(home, ".cache");
      Filename.concat(cacheDir, "{{ project_slug }}");
    };
  });

let getDocs = () => [{{ project_slug| modulify }}_CACHE_DIR.docInfo];