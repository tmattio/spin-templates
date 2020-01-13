open Test_framework;

describe("Integration Test `--version`", ({test, _}) => {
  test("Get version", ({expect}) => {
    let version = Test_utils.run([|"--version"|]);
    let generated = expect.string(version |> String.strip);
    generated.toMatch("^\\d+.\\d+.\\d+$");
  })
});
