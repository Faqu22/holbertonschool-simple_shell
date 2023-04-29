#include "main.h"

/**
 * execCom - makes a fork and executes the command from the input
 * @args: the array that contains the command
 * Return: status
 */

int execCom(char **args)
{
	int status = 0;
	pid_t pid = 0;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		execve(args[0], args, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		return (WEXITSTATUS(status));
	}
}

char *_getenv(char *string);

/**
 * _which - checks if the command exist
 * @args: a string with the command
 * Return: if exists the full path of that command, else NULL
 */

char *_which(char *args)
{
	char *list = NULL;
	char *comm = NULL;
	char *path = NULL;

	if (strchr(args, '/') && access(args, F_OK) == 0)
	{
		list = strdup(args);
		free(args);
		return (list);
	}
	list = _getenv("PATH");
	if (list == NULL)
		return (NULL);
	path = strtok(list, ":");
	while (path)
	{
		comm = malloc(strlen(path) + strlen(args) + 2);
		if (comm == NULL)
			return (NULL);
		sprintf(comm, "%s/%s", path, args);
		if (access(comm, F_OK) == 0)
		{
			free(list);
			free(args);
			return (comm);
		}
		path = strtok(NULL, ":");
		free(comm);
	}
	if (list)
		free(list);
	if (path)
		free(path);
	return (NULL);
}

/**
 * _getenv - looks for an enviornmental variable
 * @string: a string with the command
 * Return: the value of the variable if exist, else NULL
 */

char *_getenv(char *string)
{
	int i = 0;
	char *cont = NULL;
	char *aux = NULL;
	char *dup = NULL;

	for (i = 0; environ[i]; i++)
	{
		dup = strdup(environ[i]);
		cont = strtok(dup, "=");
		if (strcmp(string, cont) == 0)
		{
			cont = strtok(NULL, "=");
			if (cont == NULL)
			{
				free(dup);
				return (NULL);
			}
			aux = malloc(strlen(cont) + 1);
			strcpy(aux, cont);
			free(dup);
			return (aux);
		}
		free(dup);
	}
	return (NULL);
}

/**
 * printEnv - prints the env environmental
 */

void printEnv(void)
{
	int i = 0;

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
}

/**
 * auxCase - checks command for special cases, executes if true
 * @args: the array with the commands
 * Return: 0 if it a special case, 1 if not
 */

int auxCase(char **args)
{
	char *home = NULL, *oldpwd = NULL, *cwd = NULL;
	size_t size = 1024;

	if (strcmp(args[0], "\n") == 0)
		return (0);
	else if (strcmp(args[0], "env") == 0)
	{
		printEnv();
		return (0);
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		oldpwd = _getenv("PWD");
		home = _getenv("HOME");
		if (args[1] == NULL)
		{
			chdir(home);
		}
		else if (chdir(args[1]) != 0)
		{
			perror("No exist this path");
			return (0);
		}
		cwd = malloc(strlen(getcwd(NULL, size)) + 1);
		getcwd(cwd, size);
		_setenv("PWD", cwd);
		_setenv("OLDPWD", oldpwd);
		free(home);
		free(oldpwd);
		free(cwd);
		return (0);
	}
	return (1);
}
