type routes =
  | Home
  | NotFound;

let useRoute = () => {
  let url = ReasonReactRouter.useUrl();
  let hash = url.hash |> Js.String.split("/");

  switch (hash) {
  | [|""|] => Home
  | _ => NotFound
  };
};

[@react.component]
let make = () => {
  let route = useRoute();

  switch (route) {
  | Home => <Page_home />
  | NotFound => <Page_not_found />
  };
};
