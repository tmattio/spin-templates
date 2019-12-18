open {{ project_slug | camel_case }};

let get_tempdir = prefix => {
  Printf.sprintf(
    "{{ project_slug }}-test-%s-%s",
    prefix,
    Unix.time() |> Float.to_int |> Int.to_string,
  )
  |> Caml.Filename.concat(Caml.Filename.get_temp_dir_name());
};
