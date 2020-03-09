.PHONY: all build test clean doc doc-path format watch utop release

all:
	dune build @install

build:
	dune build

install:
	dune install

test:
	{% if test_framework == 'Rely' %}dune exec test/test_runner.exe{% else %}dune build @test/runtest -f{% endif %}

clean:
	dune clean

doc:
	dune build @doc

doc-path:
	@echo "_build/default/_doc/_html/index.html"

format:
	dune build @fmt --auto-promote

watch:
	dune build --watch

utop:
	dune utop lib -- -implicit-bindings

release:
	sh script/release.sh
