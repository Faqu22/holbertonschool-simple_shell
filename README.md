# Simple-Shell
The objective of this proyect is to make simple shell

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

`` gcc *.c -o "NAME" ``  "NAME" the name you want the shell to have
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

`` ./"NAME" ``

Now in your terminal you see this:

`` $ ``

With the shell in this state you can already type your commands
example:

``$ ls ``
