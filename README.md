## Description

<br />

`⚠️ Around October 2023, I started making this project in Go. Then, I decided to rewrite this in C to test if I have the skill to do so. I make this project without using LLMs and I can prove that` [here](https://www.youtube.com/@nihilistictinker)`. I now this only a simple project and I know programming is already a solve problem and I'm pretty sure LLMs can code this 100x much better. I know, I'm stupid for hardcoding this project when LLMs can do it now. But, that's not the point. Programming is my primary intellectual activity and it helps me think and I don't want to outsource my thinking. This is the end of the line of this project. I'm gonna proceed to a new one. If you want to continue this project and make this better, kindly fork the project. Thank you.`

<br />

<img width="451" height="312" alt="image" src="https://github.com/user-attachments/assets/40d8aa80-4fcc-44b7-93ca-9dbdfe6da92d" />

<br />

> - A CLI tool that converts number system.
> - This will support binary, decimal, octal, and hexadecimal systems.

<br />

| `Features` | `Completed` |
| ------------------- | ----------- |
| `Binary to Decimal` | `✅` |
| `Binary to Octal` | `✅` |
| `Binary to Hexadecimal` | `✅` |
| `Decimal to Binary` | `✅` |
| `Decimal to Octal` | `✅` |
| `Decimal to Hexadecimal` | `✅` |
| `Octal to Binary` | `✅` |
| `Octal to Decimal` | `✅` |
| `Octal to Hexadecimal` | `✅` |
| `Hexadecimal to Binary` | `✅` |
| `Hexadecimal to Decimal` | `✅` |
| `Hexadecimal to Octal` | `✅` |





<br />
<br />
<br />



## Development

> - Install [`GNU Make`](https://www.gnu.org/software/make/), [`GNU Debugger (GDB)`](https://www.sourceware.org/gdb/), [`GNU Compiler Collection (GCC)`](https://gcc.gnu.org/onlinedocs/), and [`Valgrind`](https://valgrind.org/)

> - For easy search and navigation of codebase, install [ctags](https://github.com/universal-ctags/ctags).

```bash
# Index the codebase with ctags.
ctags -R *

# In Neovim/Vim search for file.
:tag <name>
```

> - Below the are the development commands.

```bash
# Build and run the test.
make run-test bin=compute_binary_tests

# Build and run the program using GDB.
make run-gdb

# Build and run the program with Valgrind.
make run
```
