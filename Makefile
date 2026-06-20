WARNING_FLAGS = -Werror -Wfatal-errors -Wpedantic -Wall -Wextra

build:
	# -lm: Explicitly link agains the math library (libm).
	# -g: Generate a debugging information.
	gcc -g ${WARNING_FLAGS} -o ./bin/main ./src/main.c -lm

build-test:
	gcc -g ${WARNING_FLAGS} -o ./bin/tests/binary_tests ./src/menu/compute_binary/__tests__/binary_tests.c -lm
	gcc -g ${WARNING_FLAGS} -o ./bin/tests/helper_tests ./src/menu/helper/__tests__/helper_tests.c

run-test: build-test
	# e.g. make run-test bin="binary_tests"
	./bin/tests/${bin}

run-valgrind: build
	valgrind --leak-check=full --leak-resolution=high --track-origins=yes -s ./bin/main

run-gdb: build
	gdb ./bin/main

run: build
	./bin/main
