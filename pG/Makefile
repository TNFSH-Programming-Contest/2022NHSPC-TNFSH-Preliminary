.PHONY: statement tests

statement: statement/index.pdf

tests: tests/*.in tests/*.out

statement/index.pdf: statement/index.md statement/*.jpg problem.json subtasks.json
	tps statement

tests/*.in tests/*.out: gen/** gen/manual/** solution/**
	tps gen -s
