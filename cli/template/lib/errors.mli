exception Missing_env_var of string

val handle_errors : (unit -> 'a) -> 'a

type error =
  { doc : string
  ; exit_code : int
  }

val all : unit -> error list
