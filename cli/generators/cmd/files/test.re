open TestFramework;

describe("Test Integration `{{ project_slug | snake_case }} {{ name | snake_case }}`", ({test, _}) => {
  test("Validate standard output", ({expect}) => {
    let output = run([|"{{ name | snake_case }}"|]);
    expect.string(output |> String.strip).toMatch("Hello World!");
  })
});
