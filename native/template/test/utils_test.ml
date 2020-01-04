open Test_framework

(** Test suite for the Utils module. *)

let test_addition { expect } =
  let result = expect.int (1 + 1) in
  result.toBe 2

let () =
  describe "my first test suite" (fun { test; _ } ->
      test "1 + 1 should equal 2" test_addition)
