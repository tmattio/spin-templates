open {{ project_slug | modulify }}

(** Create a new temporary directory.

    The directory name will be prefixed with "{{ project_slug }}-test-" and will
    be suffixed with a timestamp. *)
let get_tempdir name =
  Printf.sprintf
    "{{ project_slug }}-test-%s-%s"
    name
    (Unix.time () |> Float.to_int |> Int.to_string)
  |> Caml.Filename.concat (Caml.Filename.get_temp_dir_name ())

{%- if test_framework == 'Rely' %}
let exe_path = 
  {%- if package_manager == 'Opam' %}
  Lwt_process.pread_chars ("", [| "opam"; "exec"; "--"; "dune"; "exec"; "which"; "{{ snake_case }}" |])
  {% elif package_manager == 'Esy' %}
  Lwt_process.pread_chars ("", [| "esy"; "x"; "which"; "{{ snake_case }}" |])
  {%- endif %}
  |> Lwt_stream.to_string
  |> (Lwt.map String.strip)
  |> Lwt_main.run
{%- elif test_framework == 'Alcotest' %}
let exe_path = "../bin/{{ project_slug | snake_case }}_app.exe"
{%- endif %}

(** Run {{ project_name }} binary with the given arguments and return the standard output. *)
let run args =
  let arguments = Array.append [| exe_path |] args in
  let env =
    Unix.environment ()
    |> Array.append
         [| Printf.sprintf
              "%s=%s"
              {{ project_slug | modulify }}.Config.{{ project_slug | snake_case | upper }}_CACHE_DIR.name
              (get_tempdir "cache_dir")
         |]
  in
  Lwt_process.pread_chars ~env ("", arguments)
  |> Lwt_stream.to_string
  |> Lwt_main.run
