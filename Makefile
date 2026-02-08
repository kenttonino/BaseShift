build:
	# -lm: Explicitly link agains the math library (libm).
	# -g: Generate a debugging information.
	gcc -Werror -Wfatal-errors -g -o ./bin/main ./src/main.c -lm

build_tests:
	gcc -Werror -Wfatal-errors -o ./bin/tests/binary_tests ./src/menu/binary/__tests__/binary_tests.c

tests: build_tests
	./bin/tests/binary_tests

debug: build
	gdb ./bin/main

run: build
	./bin/main
