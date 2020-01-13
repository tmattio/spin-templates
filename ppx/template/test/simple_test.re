open Test_framework;
open {{ project_slug | modulify }};

describe("Test Simple", ({test, describe, _}) => {
  test("5 + 5 should equal 10", ({expect}) => {
    let result = expect.int([%{{ project_slug | snake_case }} 5]);
    result.toBe(10);
  })
});
