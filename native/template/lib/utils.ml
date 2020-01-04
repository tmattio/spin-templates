let hello () =
  let open Pastel in
  Pastel.createElement
    ~children:
      [ Pastel.createElement ~color:Red ~children:[ "Hello" ] ()
      ; ", "
      ; Pastel.createElement ~color:Green ~children:[ "World" ] ()
      ; "!"
      ]
    ()
