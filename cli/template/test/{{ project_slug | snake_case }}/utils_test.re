open Test_framework;
open {{ project_slug | modulify }};

describe("Test Utils", ({test, describe, _}) => {
  test("greet returns the expected value", ({expect}) => {
    let generated = Utils.greet("Tom");
    expect.string("Hello Tom!").toEqual(generated);
  })
});
