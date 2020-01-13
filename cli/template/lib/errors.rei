exception Missing_env_var(string);

let handle_errors: (unit => 'a) => 'a;

type error = {
  doc: string,
  exit_code: int,
};

let all: unit => list(error);
