build:
	gcc -g -o bin/baseshift src/main.c

debug:
	make build
	gdb bin/baseshift

baseshift:
	make build
	bin/baseshift
