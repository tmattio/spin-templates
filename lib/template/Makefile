.PHONY: all build test clean doc doc-path format watch utop release

all:
	opam exec -- dune build @install

build:
	opam exec -- dune build

install:
	opam exec -- dune install

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

release:
	opam exec -- sh script/release.sh
