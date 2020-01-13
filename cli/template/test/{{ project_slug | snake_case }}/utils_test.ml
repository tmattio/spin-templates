open Test_framework
open {{ project_slug | modulify }}

let () =
  describe "Test Utils" @@ fun { test; describe; _ } ->
  test "greet returns the expected value" @@ fun { expect } ->
  let generated = Utils.greet "Tom" in
  (expect.string "Hello Tom!").toEqual generated
