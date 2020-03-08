let ten = string_of_int [%{{ project_slug | snake_case }} 5]
let () = Js.log ten
