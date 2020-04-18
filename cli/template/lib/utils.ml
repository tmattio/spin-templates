module Filename = struct
  let ensure_trailing s =
    match String.get s (String.length s - 1) with
    | '/' ->
      s
    | _ ->
      s ^ "/"
end

let greet name = "Hello " ^ name ^ "!"
