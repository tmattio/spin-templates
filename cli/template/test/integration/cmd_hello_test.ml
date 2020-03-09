{% if test_framework == 'Rely' -%}
open Test_framework
open {{ project_slug | modulify }}

(** Integration test suite for the hello command. *)

let test_hello_world name { expect } =
  let output = Test_utils.run [| "hello"; "World" |] in
  let generated = expect.string (output |> String.strip) in
  (expect.string generated).toEqual "Hello World!"

let () =
  describe "Integration test `hello`" @@ fun { test; _ } ->
  test "can display hello world" test_hello_world
{%- else -%}
open Alcotest
open {{ project_slug | modulify }}

(** Integration test suite for the hello command. *)

let test_hello_world name () =
  let output = Test_utils.run [| "hello"; "World" |] in
  let generated = expect.string (output |> String.strip) in
  check string "same string" generated "Hello World!"

let suite =
  [ "can display hello world", `Quick, test_hello_world
  ]
{% endif %}