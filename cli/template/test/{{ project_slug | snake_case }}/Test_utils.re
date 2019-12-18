open TestFramework;
open {{ project_slug | camel_case }};

describe("Test Utils", ({test, _}) => {
  test("greet returns the expected value", ({expect}) => {
    let generated = Utils.greet("Tom");
    expect.string("Hello Tom!").toEqual(generated);
  })
});
