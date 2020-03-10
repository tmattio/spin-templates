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

(** Run {{ project_name }} binary with the given arguments and return the
    standard output. *)
let run args =
  {%- if test_framework == 'Rely' and package_manager == 'Opam' %}
  let arguments = args |> Array.append [| "make"; "start"; "--" |] in
  {% elif test_framework == 'Rely' and package_manager == 'Esy' %}
  let arguments = args |> Array.append [| "esy"; "start" |] in
  {%- elif test_framework == 'Alcotest' %}
  let arguments = args |> Array.append [| "../bin/{{ project_slug | snake_case }}.exe" |] in
  {%- endif %}
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
