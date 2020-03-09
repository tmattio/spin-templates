open Test_framework;
open {{ project_slug | modulify }};

describe("Integration Test `--version`", ({test, _}) => {
  test("Get version", ({expect}) => {
    let version = Test_utils.run([|"--version"|]);
    let generated = expect.string(version |> String.strip);
    generated.toMatch("%%VERSION%%");
  })
});
