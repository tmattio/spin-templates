open {{ project_slug | modulify }}

(** Main entry point for our application. *)

let () = Stdio.Out_channel.print_endline @@ Utils.hello ()
