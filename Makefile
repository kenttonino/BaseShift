build:
	# -lm: Explicitly link agains the math library (libm).
	# -g: Generate a debugging information.
	gcc -Werror -Wfatal-errors -g -o ./bin/main ./src/main.c -lm

debug:
	make build
	gdb bin/main

run:
	make build
	bin/main
