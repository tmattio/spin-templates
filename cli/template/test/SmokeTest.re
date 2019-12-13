open TestFramework;

describe("Smoke test", ({test, _}) => {
  test("Get version", ({expect}) => {
    let version = run([|"--version"|]);
    expect.string(version |> String.trim).toMatch("^\\d+.\\d+.\\d+$");
  })
});