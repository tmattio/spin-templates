{% if test_framework == 'Rely' -%}
open Test_framework
open {{ project_slug | modulify }}

(** Integration test suite for the hello command. *)

let test_hello_world { expect } =
  let output = Test_utils.run [| "hello"; "World" |] in
  let generated = String.strip output in
  (expect.string generated).toEqual "Hello World!"

let () =
  describe "Integration test hello" @@ fun { test; _ } ->
  test "can display hello world" test_hello_world
{%- else -%}
open Alcotest
open {{ project_slug | modulify }}

(** Integration test suite for the hello command. *)

let test_hello_world () =
  let output = Test_utils.run [| "hello"; "World" |] in
  let generated = String.strip output in
  check string "same string" generated "Hello World!"

let suite =
  [ "can display hello world", `Quick, test_hello_world
  ]
{% endif %}