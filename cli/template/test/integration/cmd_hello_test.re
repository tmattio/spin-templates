open Test_framework;
open {{ project_slug | modulify }};

describe("Integration Test `{{ project_slug }} hello`", ({test, _}) => {
  test("Validate standard output", ({expect}) => {
    let output = Test_utils.run([|"hello", "World"|]);
    let generated = expect.string(output |> String.strip);
    generated.toMatch("Hello World!");
  })
});
