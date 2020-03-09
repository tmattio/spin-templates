open Test_framework
open {{ project_slug | modulify }}

let () =
  describe "Integration Test `--version`" @@ fun { test; _ } ->
  test "Get version" @@ fun { expect } ->
  let version = Test_utils.run [| "--version" |] in
  let generated = expect.string (version |> String.strip) in
  generated.toMatch "%%VERSION%%"
