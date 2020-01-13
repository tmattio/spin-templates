open Test_framework

let () =
  describe "Integration Test `{{ project_slug }} hello`" @@ fun { test; _ } ->
  test "Validate standard output" @@ fun { expect } ->
  let output = Test_utils.run [| "hello"; "World" |] in
  let generated = expect.string (output |> String.strip) in
  generated.toMatch "Hello World!"
