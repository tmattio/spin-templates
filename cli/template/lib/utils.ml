module Filename = struct
  let ensure_trailing s =
    match Caml.String.get s (Caml.String.length s - 1) with
    | '/' ->
      s
    | _ ->
      s ^ "/"
end

let greet name = "Hello " ^ name ^ "!"
