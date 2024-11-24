build:
	gcc -g -o bin/baseshift src/main.c -lm

debug:
	make build
	gdb bin/baseshift

baseshift:
	make build
	bin/baseshift
