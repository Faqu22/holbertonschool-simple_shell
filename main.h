#ifndef SHELL
#define SHELL

#include <unistd.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int execCom(char **args);
void printEnv(void);
char *_getenv(char *string);
char *_which(char *string);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
char *strtok(char *str, const char *delim);
char *strdup(const char *s);
#endif
