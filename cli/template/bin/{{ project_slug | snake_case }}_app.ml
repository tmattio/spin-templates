open Cmdliner

let defaultCmd =
  let doc = "{{ project_description }}" in
  let open Term in
  ( ret (const (fun _ -> `Help (`Pager, None)) $ const ())
  , info
      "{{ project_slug }}"
      ~doc
      ~envs:Man.envs
      ~version:Man.version
      ~exits:Man.exits
      ~man:Man.man
      ~sdocs:Man.sdocs )

let argv =
  Sys.get_argv ()
  |> Array.map ~f:(fun arg -> match arg with "-v" -> "--version" | x -> x)

let _ = Term.exit @@ Term.eval_choice defaultCmd Commands.all ~argv
