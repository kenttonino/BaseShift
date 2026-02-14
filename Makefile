build:
	# -lm: Explicitly link agains the math library (libm).
	# -g: Generate a debugging information.
	gcc -Werror -Wfatal-errors -g -o ./bin/main ./src/main.c -lm

build_test:
	gcc -Werror -Wfatal-errors -o ./bin/tests/binary_tests ./src/menu/binary/__tests__/binary_tests.c -lm

test: build_test
	./bin/tests/binary_tests

debug: build
	gdb ./bin/main

run: build
	./bin/main
