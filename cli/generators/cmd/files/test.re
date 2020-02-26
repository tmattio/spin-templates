open Test_framework;
open {{ project_slug | modulify }};

describe("Test Integration `{{ project_slug }} {{ cmd_name | slugify }}`", ({test, _}) => {
  test("Validate standard output", ({expect}) => {
    let output = Test_utils.run([|"{{ cmd_name | slugify }}"|]);
    expect.string(output |> String.strip).toMatch("Hello World!");
  })
});
