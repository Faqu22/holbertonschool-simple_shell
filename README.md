# Simple-Shell
The objective of this proyect is to make simple shell

#Requirements

General
	Allowed editors: vi, vim, emacs

	All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89

	All your files should end with a new line

	A README.md file, at the root of the folder of the project is mandatory

	Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl

	Your shell should not have any memory leaks

	No more than 5 functions per file

	All your header files should be include guarded

	Use system calls only when you need to

# List of allowed functions and system calls

	all functions from strings.h

	access (man 2 access)

	chdir (man 2 chdir)

	close (man 2 close)

	closedir (man 3 closedir)

	execve (man 2 execve)

	exit (man 3 exit

	_exit (man 2 _exit)

	fflush (man 3 fflush)

	fork (man 2 fork)

	free (man 3 free)

	getcwd (man 3 getcwd)

	getline (man 3 getline)

	getpid (man 2 getpid)

	isatty (man 3 isatty)

	kill (man 2 kill)

	malloc (man 3 malloc)

	open (man 2 open)

	opendir (man 3 opendir)

	perror (man 3 perror)

	printf (man 3 printf)

	fprintf (man 3 fprintf)

	vfprintf (man 3 vfprintf)

	sprintf (man 3 sprintf)

	putchar (man 3 putchar)

	read (man 2 read)

	readdir (man 3 readdir)

	signal (man 2 signal)

	stat (__xstat) (man 2 stat)

	lstat (__lxstat) (man 2 lstat)

	fstat (__fxstat) (man 2 fstat)

	strtok (man 3 strtok)

	wait (man 2 wait)

	waitpid (man 2 waitpid)

	wait3 (man 2 wait3)

	wait4 (man 2 wait4)

	write (man 2 write)

# Instalation
First clone this repository

`` git clone https://github.com/Faqu22/holbertonschool-simple_shell.git ``

Compile it

`` gcc *.c -o hsh ``
# Usage

The shell can be used either in interactive mode

```shell

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

```
or in non-interactive mode

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

```
To use it in interactive mode you have to run the shell:

`` ./"hsh" ``

Now in your terminal you see this:

`` $ ``

With the shell in this state you can already type your commands
example:

``$ ls ``

# Flowchart

![flowchart](https://viewer.diagrams.net/?tags=%7B%7D&target=blank&highlight=0000ff&edit=_blank&layers=1&nav=1&title=Flowchar.png#R7VpbV9s4EP41OWf3gR7fSR4JBMpul3YPdFMehS1sLbLllRWI%2B%2BtXsuWrnMQUHKcnfUIaT3SZb74ZjdDEPA%2FXVxTEwV%2FEg3hiaN56Yl5MDEO3HJ3%2FEZJUSma6kUt8ijwpqwS36DuUQk1KV8iDSUOREYIZiptCl0QRdFlDBiglL021R4Kbs8bAh4rg1gVYlS6Rx4JcOjVOK%2FlHiPygmFl3ZvmXEBTKcidJADzyUhOZi4l5TglheStcn0MsrFfYZXmdLvGnJ%2Bfqj7%2BT%2F8DX%2BZ93N%2F%2Bc5INdvuYn5RYojNj7Di2xfAZ4Je0l98rSwoCUrCIPikG0iTkPWIh5U%2BfNfyFjqQQcrBjhIkJZQHwSAfyJkFjqPZKISTVd9GHknQlgef8BE%2FcpF10ijOUcvCf1p7yXMEqeSuzEACUQQhmDB4jnwH3ys4WeE0wo%2FxSRCIqhPO4Mci%2FV4haVdN7TthKDhKyoC7fomdLFAfXhtvGcXE%2Bsr%2BanErkrSELIaMoVKMSAoeemMwPJCb%2FUq3DnDQl9txvEZ%2BHSY%2BuLyLl5%2FHxthHN2TU70UwX23ZZrOkYn9B0uUnMgbnGafhO%2F%2F2AX3fvSB3jnYt3opbI3PGTdRtLGwmzbsmvURUkCuL1%2F%2Bz1bA1vRiDe4oS%2B3cFrg8BIgBm9jkFnpheeBJkx1%2FvLtzn0MkkRCsYOcr0PqGVIG11tNW3w9lVjIrDSV3ZcqwusFXEEtulvaQAQ6Zv44PUPegfHHUfhzgZIYgzSZiPRuqaQJSPiwSnYTpkEBwZ5LECIsrP8R4mfIkAs6aAUw8iPecTkqkHZzi0%2BJIp%2F3nKp3l3nLibVHupX9Ot%2B0Dr5Nh%2BKbrivo3XyeGA7mE88fKG%2F5rDTIWKxscLKi6H5YWbDtZ0trxXJqyH5NOB8M7S6NeSGhYOySMASR94uuG%2BlqzMam6%2Bw40mM3v3qmR%2FOwKgKFhR%2F4OEESqEhizGt5uJtng7m703T3E7PD3Y19urtaVacicrUMx7fHmhZSYoowAg8%2F%2BEx%2BCJHn5eSACfoOHrKhhM%2FGBEUs24Y9n9gXYizOh0TGqzI6tarjR15zt0RDgWSYrSOEMVVAsjowMofCyFYwWgLEkuyKSWSbVZ50UBSvWI%2BDxXGBqbcSjN3BOHOfaOpW53nwGE5%2FWw91u09%2FB5Z2pgqO94vbwzjYjwaRcVAQGSpE1xwhbfHt%2Bu6oYLHfGxb50y8i%2FG8OtlY7iOYrlb%2BqwD2jFKQ1NZlVNs%2FTOkaZduv%2FCTv0i3Vt1De26vNGvuLKM0sbviGeqNVkWS9qcI0S1nU9OvqR1jR6VHD7PdJqqpV%2BPm6%2FeyTtdnW7DZ%2Fej7LqQLMWZ%2BzWQPmW38x9x%2B6eZ9O62vrFBgflcoHDLxfs4YKW1kTI7pk13g0stb5Cj7zPK5OsquIlEXCz%2FR3xzZDR86hhHNYJsFh3DdvFGrorxsHUNl3Hjp9TrVaM08fOqfqsmyOHwg59MmoJO9pTih9KobY1QkrU1UcAX2i%2BTg1Sml1khTBJxBupgyOkNTu0Q66uJq1FVikQQcuYEp%2BCUDFkk3AHcglu9TXmYFdyhuqbI1%2FJNeKZvt9oVqTwsa4V3nobYJ%2B%2B7jbA3nUbMN2qP1AFcaq4ZHa7OIJPrhErb4l5%2B77WrhxSdEb3x3d%2FHvBD%2Fmi2bsGKdLvJv9r6uypa09yqP5A%2FqgfpAIjcHRIKN7506HgDsSUn9XjgN1ROap%2B4yyPSrpzkvD4n8W71EjvHp3rQbi7%2BBw%3D%3D)

# List of files

Documentations: README.md, AUTHORS, man_1_simple_shell.

Shell: main.c

Auxiliar functions: auxFunc.h, more_AuxFunc.c

# Authors

Facundo Alvarez

Federico Heuer
