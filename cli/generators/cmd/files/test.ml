{% if test_framework == 'Rely' -%}
open Test_framework
open {{ project_slug | modulify }}

(** Integration test suite for the {{ cmd_name | snake_case }} command. *)

let test_{{ cmd_name | snake_case }} name { expect } =
  let output = Test_utils.run [| "hello"; "World" |] in
  let generated = String.strip output in
  (expect.string generated).toEqual "Hello World!"

let () =
  describe "Integration test `hello`" @@ fun { test; _ } ->
  test "{{ cmd_name | slugify }}` returns the expected output" test_{{ cmd_name | snake_case }}
{%- else -%}
open Alcotest
open {{ project_slug | modulify }}

(** Integration test suite for the {{ cmd_name | snake_case }} command. *)

let test_{{ cmd_name | snake_case }} name () =
  let output = Test_utils.run [| "hello"; "World" |] in
  let generated = String.strip output in
  check string "same string" generated "Hello World!"

let suite =
  [ "{{ cmd_name | slugify }}` returns the expected output", `Quick, test_{{ cmd_name | snake_case }}
  ]
{% endif %}