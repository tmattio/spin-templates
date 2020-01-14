open Test_framework
open {{ project_slug | modulify }}

let () =
  describe "Test Simple" @@ fun { test; describe; _ } ->
  test "5 + 5 should equal 10" @@ fun { expect } ->
  let result = expect.int ([%{{ project_slug | snake_case }} 5]) in
  result.toBe 10
