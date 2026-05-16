WARNING_FLAGS = -Werror -Wfatal-errors -Wpedantic -Wall -Wextra

build:
	# -lm: Explicitly link agains the math library (libm).
	# -g: Generate a debugging information.
	gcc -g ${WARNING_FLAGS} -o ./bin/main ./src/main.c -lm

build_test:
	gcc -g ${WARNING_FLAGS} -o ./bin/tests/binary_tests ./src/menu/binary/__tests__/binary_tests.c -lm

run-test: build_test
	# e.g. make run-test bin="binary_tests"
	./bin/tests/${bin}

run-valgrind: build
	valgrind --leak-check=full --leak-resolution=high ./bin/main

run-debug: build
	gdb ./bin/main

run: build
	./bin/main
