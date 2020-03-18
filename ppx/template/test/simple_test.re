{% if test_framework == 'Rely' -%}
open Test_framework;
open {{ project_slug | modulify }};

/** Test suite to showcase a simple unit test with Alcotest */

let test_hello_with_name = ({expect}) => {
  let result = [%{{ project_slug | snake_case }} 5];
  expect.int(result).toBe(10);
};

describe("Simple", ({test, _}) => {
  test("5 + 5 should equal 10", test_hello_with_name);
});
{%- else -%}
open Alcotest;
open {{ project_slug | modulify }};

/** Test suite to showcase a simple unit test with Alcotest */

let test_simple_addition = () => {
  let result = [%{{ project_slug | snake_case }} 5];
  check(int, "same value", 10, result);
};

let suite = [("5 + 5 should equal 10", `Quick, test_simple_addition)];
{% endif %}