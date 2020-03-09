{% if test_framework == 'Rely' -%}
open Test_framework
open {{ project_slug | modulify }}

(** Integration test suite that performs smoke tests. *)

let test_version name { expect } =
  let version = Test_utils.run [|"--version"|] in
  let generated = String.strip version in
  (expect.string generated).toEqual "%%VERSION%%"

let () =
  describe "Integration test `--version" @@ fun { test; _ } ->
  test "can display the version" test_version
{%- else -%}
open Alcotest
open {{ project_slug | modulify }}

(** Integration test suite that performs smoke tests. *)

let test_version name () =
  let version = Test_utils.run [|"--version"|] in
  let generated = String.strip version in
  check string "same string" generated "%%VERSION%%"

let suite =
  [ "can display the version", `Quick, test_version
  ]
{% endif %}