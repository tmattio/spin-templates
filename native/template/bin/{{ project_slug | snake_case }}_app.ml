open {{ project_slug | modulify }}

(** Main entry point for our application. *)

let () = Stdio.print_endline @@ Utils.greet "World"
