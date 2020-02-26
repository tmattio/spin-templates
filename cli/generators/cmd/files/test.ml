open Test_framework
open {{ project_slug | modulify }}

let () =
  describe "Test Integration `{{ project_slug }} {{ cmd_name | slugify }}`"
  @@ fun { test; _ } ->
  test "Validate standard output" @@ fun { expect } ->
  let output = Test_utils.run [| "{{ cmd_name | slugify }}" |] in
  let generated = expect.string (output |> String.strip) in
  generated.toMatch "Hello World!"
