# Spin Templates

Official templates for Spin.

| Template             | Type   | Description                                                    | Build                                                                                   |
|----------------------|--------|----------------------------------------------------------------|-----------------------------------------------------------------------------------------|
| [`native`](./native) | Native | A native project containing the minimum viable configurations. | ![Actions Status](https://github.com/tmattio/spin-templates/workflows/native/badge.svg) |
| [`cli`](./cli)       | Native | Native command line interface.                                 | ![Actions Status](https://github.com/tmattio/spin-templates/workflows/cli/badge.svg)    |
| [`lib`](./lib)       | Native | A simple native library.                                       | ![Actions Status](https://github.com/tmattio/spin-templates/workflows/lib/badge.svg)    |
| [`ppx`](./ppx)       | Native | A PPX library to be used in native or web applications.        | ![Actions Status](https://github.com/tmattio/spin-templates/workflows/ppx/badge.svg)    |
| [`react`](./react)   | Web    | React Single-Page-Application in Reason.                       | ![Actions Status](https://github.com/tmattio/spin-templates/workflows/react/badge.svg)  |

## Guidelines

The official templates are high-quality templates that are ready for the real world
Here are some guidelines that we follow when creating a template:

- Offer a Reason and OCaml version
- Provide a CI/CD with Github Actions
- Create real unit tests and integration tests
- Include documentation generation from markdown and code
- Deploy release artifact (e.g. Docker images, binaries, static web files, etc.)
