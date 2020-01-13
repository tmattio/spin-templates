type 't variable_doc =
  { name : string
  ; doc : string
  ; default : string
  }

module EnvVar (M : sig
  type t

  val name : string

  val doc : string

  val default : t

  val parse : string -> t

  val unparse : t -> string
end) =
struct
  include M

  let opt_value = Sys.getenv name |> Option.map ~f:parse

  let get_opt () = opt_value

  let get () = get_opt () |> Option.value ~default

  let doc_info = { name; doc; default = unparse default }
end

let getenv_exn name =
  let fn () =
    match Sys.getenv name with
    | Some env ->
      env
    | _ ->
      raise (Errors.Missing_env_var name)
  in
  Errors.handle_errors fn

module {{ project_slug | snake_case | uppercase }}_CACHE_DIR = EnvVar (struct
  type t = string

  let parse = Utils.Filename.ensure_trailing

  let unparse = Utils.Filename.ensure_trailing

  let name = "{{ project_slug | snake_case | uppercase }}_CACHE_DIR"

  let doc = "The directory where the cached data is stored."

  let default =
    let home =
      match Caml.Sys.os_type with
      | "Unix" ->
        getenv_exn "HOME"
      | _ ->
        getenv_exn "APPDATA"
    in
    let cache_dir = Caml.Filename.concat home ".cache" in
    Caml.Filename.concat cache_dir "{{ project_slug }}"
end)

let all () = [ {{ project_slug | snake_case | uppercase }}_CACHE_DIR.doc_info ]
