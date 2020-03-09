{% if test_framework == 'Rely' -%}
open Test_framework;
open {{ project_slug | modulify }};

/** Integration test suite for the hello command. */

let test_hello_world = ({expect}) => {
  let output = Test_utils.run([|"hello", "world"|]);
  let generated = String.strip(output);
  expect.string(generated).toEqual("Hello World!");
};

describe("Integration test `hello`", ({test, _}) => {
  test("can display hello world", test_hello_world);
});
{%- else -%}
open Alcotest;
open {{ project_slug | modulify }};

/** Integration test suite for the hello command. */

let test_hello_world = () => {
  let output = Test_utils.run([|"hello", "world"|]);
  let generated = String.strip(output);
  check(string, "same string", generated, "Hello World!");
};

let suite = [
  ("can display hello world", `Quick, test_hello_world),
];
{% endif %}