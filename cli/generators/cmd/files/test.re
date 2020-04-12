{% if test_framework == 'Rely' -%}
open Test_framework;
open {{ project_slug | modulify }};

/** Integration test suite for the {{ cmd_name | snake_case }} command. */

let test_{{ cmd_name | snake_case }} = ({expect}) => {
  let output = Test_utils.run([|"{{ cmd_name | slugify }}"|]);
  let generated = String.trim(output);
  expect.string(generated).toEqual("Hello World!");
};

describe("Integration test {{ cmd_name | slugify }}", ({test, _}) => {
  test("{{ cmd_name | slugify }} returns the expected output", test_{{ cmd_name | snake_case }});
});
{%- else -%}
open Alcotest;
open {{ project_slug | modulify }};

/** Integration test suite for the {{ cmd_name | snake_case }} command. */

let test_{{ cmd_name | snake_case }} = () => {
  let output = Test_utils.run([|"{{ cmd_name | slugify }}"|]);
  let generated = String.trim(output);
  check(string, "same string", generated, "Hello World!");
};

let suite = [
  ("{{ cmd_name | slugify }} returns the expected output", `Quick, test_{{ cmd_name | snake_case }}),
];
{% endif %}