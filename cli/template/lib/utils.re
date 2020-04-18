module Filename = {
  let ensure_trailing = s =>
    switch (String.get(s, String.length(s) - 1)) {
    | '/' => s
    | _ => s ++ "/"
    };
};

let greet = name => "Hello " ++ name ++ "!";
