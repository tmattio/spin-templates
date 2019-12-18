open Cmdliner;

let man = [
  `S(Manpage.s_common_options),
  `S(Manpage.s_environment),
  `P("These environment variables affect the execution of $(mname):"),
  `S("MORE HELP"),
  `P("Use `$(mname) $(i,COMMAND) --help' for help on a single command."),
  `Noblank,
  `S(Manpage.s_bugs),
  `P("File bug reports at https://github.com/tmattio/{{ project_slug }}"),
];

let version = Package.version;

let envs =
  {{ project_slug | camel_case }}.Config.all
  |> {{ project_slug | camel_case }}.Errors.handleErrors
  |> List.map(~f=el =>
       {{ project_slug | camel_case }}.Config.(
         Term.env_info(
           ~doc=Printf.sprintf("%s\ndefaults to \"%s\"", el.doc, el.default),
           el.name,
         )
       )
     );

let sdocs = Manpage.s_common_options;

let exits =
  List.concat([
    {{ project_slug | camel_case }}.Errors.all()
    |> List.map(~f=el =>
         {{ project_slug | camel_case }}.Errors.(Term.exit_info(el.exit_code, ~doc=el.doc))
       ),
    Term.default_exits,
  ]);
