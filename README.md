# Simple-Shell
The objective of this proyect is to make simple shell.
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
