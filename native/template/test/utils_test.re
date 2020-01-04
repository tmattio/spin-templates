open Test_framework;

/** Test suite for the Utils module. */

describe("my first test suite", ({test, _}) =>
  test("1 + 1 should equal 2", ({expect}) => {
    let result = expect.int(1 + 1);
    result.toBe(2);
  })
);
