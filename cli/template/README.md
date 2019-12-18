# {{ project_name }}

[![Actions Status](https://github.com/tmattio/{{ project_slug }}/workflows/CI/CD%20Pipeline/badge.svg)](https://github.com/tmattio/{{ project_slug }}/actions)

> {{ project_description }}

## Installation

### Using Homebrew (macOS)

```bash
brew install https://raw.githubusercontent.com/tmattio/{{ project_slug }}/master/scripts/install.rb
```

### Using Chocolatey (Windows)

```bash
choco install
```

### Using npm

```bash
yarn global add @tmattio/{{ project_slug }}
# Or
npm -g install @tmattio/{{ project_slug }}
```

### Using a script

```bash
curl -fsSL https://github.com/tmattio/{{ project_slug }}/raw/master/dist/install.sh | bash
```

## Usage

### `{{ project_slug }} hello NAME`

Greets the name given in argument.

## Contributing

We would love your help improving {{ project_name }}!

### Developing

```bash
npm install -g esy
git clone git@github.com:tmattio/{{ project_slug }}.git
esy install
esy build
```

### Running Binary

After building the project, you can run the main binary that is produced.

```bash
esy x {{ project_slug }}.exe
```

### Running Tests

```bash
# Runs the "test" command in `package.json`.
esy test
```

### Repository Structure

The following snippet describes {{ project_name }}'s repository structure.

```text
.
├── .github/
|   Contains Github specific files such as actions definitions and issue templates.
│
├── docs/
|   End-user documentation in Markdown format.
│
├── executable/
|   Source for the {{ project_slug }} executable's interface, its subcommands and the man page content.
│
├── library/
|   Source for {{ project_name }}'s library. Contains most of {{ project_name }}'s internal functionnalities.
│
├── test/
|   Unit tests and integration tests for {{ project_name }}.
│
├── dune
|   Dune file used to define project-wide parameters.
│
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
