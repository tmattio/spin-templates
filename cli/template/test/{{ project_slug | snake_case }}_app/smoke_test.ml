open Test_framework

let () =
  describe "Integration Test `--version`" @@ fun { test; _ } ->
  test "Get version" @@ fun { expect } ->
  let version = Test_utils.run [| "--version" |] in
  let generated = expect.string (version |> String.strip) in
  generated.toMatch "^\\d+.\\d+.\\d+$"
