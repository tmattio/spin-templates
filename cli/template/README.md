# {{ project_name }}

[![Actions Status](https://github.com/{{ github_username }}/{{ project_slug }}/workflows/CI/badge.svg)](https://github.com/{{ github_username }}/{{ project_slug }}/actions)
[![NPM Version](https://badge.fury.io/js/%40{{ npm_username }}%2F{{ project_slug }}.svg)](https://badge.fury.io/js/%40{{ npm_username }}%2F{{ project_slug }})

{{ project_description }}

## Features

- Available on all major platform (Windows, Linux and Windows)

## Installation

### Using Homebrew (macOS)

```bash
brew install https://raw.githubusercontent.com/tmattio/{{ project_slug }}/master/scripts/tmattio-{{ project_slug }}.rb
```

### Using npm

```bash
yarn global add @{{ npm_username }}/{{ project_slug }}
# Or
npm -g install @{{ npm_username }}/{{ project_slug }}
```

### Using a script

```bash
curl -fsSL https://github.com/{{ github_username }}/{{ project_slug }}/raw/master/scripts/install.sh | bash
```

## Usage

### `{{ project_slug }} hello NAME`

Greets the name given in argument.

## Contributing

We would love your help improving {{ project_name }}!

### Developing

You need Esy, you can install the latest version from [npm](https://npmjs.com):

```bash
yarn global add esy@latest
# Or
npm install -g esy@latest
```

> NOTE: Make sure `esy --version` returns at least `0.5.8` for this project to build.

Then run the `esy` command from this project root to install and build depenencies.

```bash
esy
```

Now you can run your editor within the environment (which also includes merlin):

```bash
esy $EDITOR
esy vim
```

Alternatively you can try [vim-reasonml](https://github.com/jordwalke/vim-reasonml)
which loads esy project environments automatically.

After you make some changes to source code, you can re-run project's build
again with the same simple `esy` command.

```bash
esy
```

This project uses [Dune](https://dune.build/) as a build system, and Pesy to generate Dune's configuration files. If you change the `buildDirs` configuration in `package.json`, you will have to regenerate the configuration files using:

```bash
esy pesy
```

### Running Binary

After building the project, you can run the main binary that is produced.

```bash
esy start
```

### Running Tests

You can test compiled executable (runs `scripts.tests` specified in `package.json`):

```bash
esy test
```

### Building documentation

Documentation for the libraries in the project can be generated with:

```bash
esy doc
open-cli $(esy doc-path)
```

This assumes you have a command like [open-cli](https://github.com/sindresorhus/open-cli) installed on your system.

> NOTE: On macOS, you can use the system command `open`, for instance `open $(esy doc-path)`

### Creating release builds

To release prebuilt binaries to all platforms, we use Github Actions to build each binary individually.

The binaries are then uploaded to a Github Release and NPM automatically.

To trigger the Release workflow, you need to push a git tag to the repository.
We provide a script that will bump the version of the project, tag the commit and push it to Github:

```bash
./scripts/release.sh
```

The script uses `npm version` to bump the project, so you can use the same argument.
For instance, to release a new patch version, you can run:

```bash
./scripts/release.sh patch
```

### Repository Structure

The following snippet describes {{ project_name }}'s repository structure.

```text
.
├── .github/
|   Contains Github specific files such as actions definitions and issue templates.
│
├── bin/
|   Source for {{ project_name }}'s binary. This links to the library defined in `lib/`.
│
├── lib/
|   Source for {{ project_name }}'s library. Contains {{ project_name }}'s core functionnalities.
│
├── test/
|   Unit tests and integration tests for {{ project_name }}.
│
├── test_runner/
|   Source for the test runner's binary.
|
├── dune-project
|   Dune file used to mark the root of the project and define project-wide parameters.
|   For the documentation of the syntax, see https://dune.readthedocs.io/en/stable/dune-files.html#dune-project
│
├── LICENSE
│
├── package.json
|   Esy package definition.
|   To know more about creating Esy packages, see https://esy.sh/docs/en/configuration.html.
│
├── README.md
│
└── {{ project_slug }}.opam
    Opam package definition.
    To know more about creating and publishing opam packages, see https://opam.ocaml.org/doc/Packaging.html.
```
