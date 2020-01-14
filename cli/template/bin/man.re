open Cmdliner;

let man = [
  `S(Manpage.s_common_options),
  `S(Manpage.s_environment),
  `P("These environment variables affect the execution of $(mname):"),
  `S("MORE HELP"),
  `P("Use `$(mname) $(i,COMMAND) --help' for help on a single command."),
  `Noblank,
  `S(Manpage.s_bugs),
  `P("File bug reports at https://github.com/{{ github_username }}/{{ project_slug }}"),
];

let version = Package.version;

let envs =
  {{ project_slug | modulify }}.Config.all
  |> {{ project_slug | modulify }}.Errors.handle_errors
  |> List.map(~f=el =>
       {{ project_slug | modulify }}.Config.(
         Term.env_info(
           ~doc=Printf.sprintf("%s\ndefaults to \"%s\"", el.doc, el.default),
           el.name,
         )
       )
     );

let sdocs = Manpage.s_common_options;

let exits =
  List.concat([
    {{ project_slug | modulify }}.Errors.all()
    |> List.map(~f=el =>
         {{ project_slug | modulify }}.Errors.(Term.exit_info(el.exit_code, ~doc=el.doc))
       ),
    Term.default_exits,
  ]);
