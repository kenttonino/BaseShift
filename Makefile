build:
	# -lm: Explicitly link agains the math library (libm).
	# -g: Generate a debugging information.
	gcc -Werror -Wfatal-errors -g -o ./bin/main ./src/main.c -lm

build_tests:
	gcc -Werror -Wfatal-errors -o ./bin/tests/binary_test ./src/menu/binary/__tests__/binary_test.c

tests:
	make build_tests
	./bin/tests/binary_test

debug:
	make build
	gdb ./bin/main

run:
	make build
	./bin/main
