#include "main.h"

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

char *_which(char *args)
{
	char *list = NULL;
	char *comm = NULL;
	char *path = NULL;

	list = _getenv("PATH");
	if (list == NULL)
		return (NULL);
	path = strtok(list, ":");
	if (strchr(args, '/') && access(args, F_OK) == 0)
	{
		free(path);
		free(list);
		return (args);
	}
	free(list);
	while (path)
	{
		comm = malloc(strlen(path) + strlen(args) + 2);
		if (comm == NULL)
			return (NULL);
		sprintf(comm, "%s/%s", path, args);
		if (access(comm, F_OK) == 0)
		{
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


char *_getenv(char *string)
{
	int i = 0;
	char *cont = NULL;
	char *aux = NULL;

	for (i = 0; environ[i]; i++)
	{
		cont = malloc(strlen(environ[i]) + 1);
		strcpy(cont, environ[i]);
		cont = strtok(cont, "=");
		if (strcmp(string, cont) == 0)
		{
			aux = strdup(strtok(NULL, "="));
			free(cont);
			return (aux);
		}
		free(cont);
	}
	return (NULL);
}

void printEnv(void)
{
	int i = 0;

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
}
int auxCase(char **args)
{
	char *home = NULL, *oldpwd = NULL, *cwd = NULL;
	size_t size = 1024;

	if (strcmp(args[0], "\n") == 0)
		return (0);
	else if (strcmp(args[0], "exit") == 0)
	{
		free_array(args);
		exit(0);
	}
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
