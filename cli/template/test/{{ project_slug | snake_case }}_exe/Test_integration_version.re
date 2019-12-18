open TestFramework;

describe("Test Integration Version", ({test, _}) => {
  test("The version matches semantic versionning format", ({expect}) => {
    let version = run([|"--version"|]);
    expect.string(version |> String.strip).toMatch("^\\d+.\\d+.\\d+$");
  })
});