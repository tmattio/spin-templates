let logger = (service, request: Morph.Request.t) => {
  open Lwt.Infix;
  let start_request = Mtime_clock.elapsed();
  service(request)
  >|= (
    response => {
      let end_request = Mtime_clock.elapsed();
      Logs.info(m =>
        m(
          "http: %s request to %s finished in %fms",
          Morph.Method.to_string(request.meth),
          request.target,
          Mtime.Span.abs_diff(start_request, end_request) |> Mtime.Span.to_ms,
        )
      );

      response;
    }
  );
};
