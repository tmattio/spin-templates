open Cmdliner;

let man = [
  `S(Manpage.s_common_options),
  `S(Manpage.s_environment),
  `P("These options are common to all commands."),
  `S("MORE HELP"),
  `P("Use `$(mname) $(i,COMMAND) --help' for help on a single command."),
  `Noblank,
  `S(Manpage.s_bugs),
];

let version = Package.version;

let envs =
  {{ project_slug | camel_case }}.Config.getDocs()
  |> List.map(el =>
       {{ project_slug | camel_case }}.Config.(
         Term.env_info(
           ~doc=Printf.sprintf("%s\ndefaults to \"%s\"", el.doc, el.default),
           el.name,
         )
       )
     );

let sdocs = Manpage.s_common_options;

let exists = Term.default_exits;