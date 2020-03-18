.PHONY: all build test clean doc doc-path format watch utop

ifeq (start,$(firstword $(MAKECMDGOALS)))
  START_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  $(eval $(START_ARGS):;@:)
endif

all:
	opam exec -- dune build @install

dev:
	opam install dune-release merlin ocamlformat utop
	{%- if test_framework == 'Rely' %}
	opam pin add -y pastel https://github.com/facebookexperimental/reason-native.git
	opam pin add -y cli https://github.com/facebookexperimental/reason-native.git
	opam pin add -y file-context-printer https://github.com/facebookexperimental/reason-native.git
	opam pin add -y rely https://github.com/facebookexperimental/reason-native.git
	{%- endif %}
	opam install --deps-only --with-test --with-doc -y .

build:
	opam exec -- dune build

install:
	opam exec -- dune install

start: all
	opam exec -- dune exec bin/{{ project_slug | snake_case }}_app.exe $(START_ARGS)

test:
	opam exec -- {% if test_framework == 'Rely' %}dune exec test/test_runner.exe{% else %}dune build @test/runtest -f{% endif %}

clean:
	opam exec -- dune clean

doc:
	opam exec -- dune build @doc

doc-path:
	@echo "_build/default/_doc/_html/index.html"

format:
	opam exec -- dune build @fmt --auto-promote

watch:
	opam exec -- dune build --watch

utop:
	opam exec -- dune utop lib -- -implicit-bindings
