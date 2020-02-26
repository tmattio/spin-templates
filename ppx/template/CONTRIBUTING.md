# Contributing

## Setup your development environment

{% if package_manager == 'Esy' %}
You need Esy, you can install the latest version from [npm](https://npmjs.com):

```bash
yarn global add esy@latest
# Or
npm install -g esy@latest
```

Then run the `esy` command from this project root to install and build depenencies.

```bash
esy
```
{% else %}
You need Opam, you can install it by following [Opam's documentation](https://opam.ocaml.org/doc/Install.html).

With Opam installed, you can install the dependencies with:

```bash
opam install --deps-only --with-test -y .
```

Then, build the project with:

```bash
make
```
{% endif %}

This project uses [Dune](https://dune.build/) as a build system, if you add a dependency in your `package.json` file, don't forget to add it to your `dune` and `dune-project` files too.

### Running Tests

You can run the test compiled executable:

{% if package_manager == 'Esy' -%}

```bash
esy test
```
{%- else %}
```bash
make test
```
{%- endif %}

This will run the native unit test. If you want to run Bucklescript's integration test instead, you can do:

```bash
cd test_bs
esy
yarn install
yarn build
```

### Building documentation

Documentation for the libraries in the project can be generated with:

{% if package_manager == 'Esy' -%}
```bash
esy doc
open-cli $(esy doc-path)
```

This assumes you have a command like [open-cli](https://github.com/sindresorhus/open-cli) installed on your system.

> NOTE: On macOS, you can use the system command `open`, for instance `open $(esy doc-path)`
{%- else %}
```bash
make doc
open-cli $(esy doc-path)
```

This assumes you have a command like [open-cli](https://github.com/sindresorhus/open-cli) installed on your system.

> NOTE: On macOS, you can use the system command `open`, for instance `open $(make doc-path)`
{%- endif %}

### Releasing

To release prebuilt binaries to all platforms, we use Github Actions to build each binary individually.

The binaries are then uploaded to a Github Release and NPM automatically.

To trigger the Release workflow, you need to push a git tag to the repository.
We provide a script that will bump the version of the project, tag the commit and push it to Github:

```bash
./script/release.sh
```

The script will release the current project version on Opam, update the documentation and push a new tag on Github.

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
├── test_bs/
|   Bucklescript integration tests for {{ project_name }}.
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
{%- if package_manager == 'Esy' %}
├── package.json
|   Esy package definition.
|   To know more about creating Esy packages, see https://esy.sh/docs/en/configuration.html.
{%- else %}
├── Makefile
|   Make file containing common development command.
{%- endif %}
│
├── README.md
│
└── {{ project_slug }}.opam
    Opam package definition.
    To know more about creating and publishing opam packages, see https://opam.ocaml.org/doc/Packaging.html.
```
