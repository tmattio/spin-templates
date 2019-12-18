let projectDir = Caml.Sys.getcwd();
let tmpDir = Caml.Filename.concat(projectDir, ".tmp");

include Rely.Make({
  let config =
    Rely.TestFrameworkConfig.initialize({
      snapshotDir:
        Caml.Filename.concat(
          projectDir,
          Caml.Filename.concat("test", "__snapshots__"),
        ),
      projectDir,
    });
});

let run = args => {
  let arguments =
    args
    |> Array.append([|"./_esy/default/build/default/executable/{{ project_slug | camel_case }}App.exe"|]);
  let env =
    Unix.environment()
    |> Array.append([|
         Printf.sprintf("%s=%s", {{ project_slug | camel_case }}.Config.{{ project_slug| modulify }}_CACHE_DIR.name, tmpDir),
       |]);
  let result =
    Lwt_process.pread_chars(~env, ("", arguments)) |> Lwt_stream.to_string;
  Lwt_main.run(result);
};
