# Simple-Shell
The objective of this proyect is to make simple shell

# Description
A Unix-like operating system uses a command line interpreter called a Unix shell, which serves as a user interface. This shell can function as both a scripting and interactive command language, and is utilized by the operating system to manage system execution through shell scripts.
# Requirements
<details open>
<summary> <strong> General </strong> </summary>

<br>

	Allowed editors: vi, vim, emacs

	All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89

	All your files should end with a new line

	A README.md file, at the root of the folder of the project is mandatory

	Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl

	Your shell should not have any memory leaks

	No more than 5 functions per file

	All your header files should be include guarded

	Use system calls only when you need to

</details>


## List of allowed functions and system calls
<details open>
<summary> <strong> Functions</strong> </summary>

<br>

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
</details>

# Instalation
First clone this repository

`` git clone https://github.com/Faqu22/holbertonschool-simple_shell.git ``

Compile it

`` gcc *.c -o hsh ``
# Usage

<details open>
<summary> <strong> Examples </strong> </summary>
<br>

The shell can be used either in interactive mode
```shell

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($) ls
hsh main.c shell.c
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

</details>

<details open>
<summary> <strong> Instructions </strong> </summary>
<br>

To use it in interactive mode you have to run the shell:

`` ./"hsh" ``

Now in your terminal you see this:

`` $ ``

With the shell in this state you can already type your commands
example:

``$ ls ``

</details>

# Flowchart

![flowchart](https://i.postimg.cc/YqL67Xrb/Flowchar.jpg)

# List of files

Documentations: README.md, AUTHORS, man_1_simple_shell.

Shell: main.c

Auxiliar functions: auxFunc.h, more_AuxFunc.c

# Authors

* <h6>Facundo Alvarez <a href="https://github.com/Faqu22"><img align="center" alt="github" src="https://i.imgur.com/hGwhvpO.png" height="30"/></a>
* <h6>Federico Heuer <a href="https://github.com/RaptorZ98"><img align="center" alt="github" src="https://i.imgur.com/hGwhvpO.png" height="30"/></a>

<hr>
