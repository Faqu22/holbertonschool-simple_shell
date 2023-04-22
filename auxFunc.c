#include "main.h"

int execCom(char **args)
{
	int status;
	pid_t pid;

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
	char *list;
	char *comm;
	char *path;

	list = _getenv("PATH");
	if (strchr(args, '/'))
		return (args);
	path = strtok(list, ":");

	while (path)
	{
		comm = malloc(sizeof(char *) * (strlen(path) + strlen(args) + 2));
		if (comm == NULL)
			return (NULL);
		sprintf(comm, "%s/%s", path, args);
		if (access(comm, F_OK) == 0)
			return (comm);
		free(comm);
		path = strtok(NULL, ":");
	}
	return (NULL);
}


char *_getenv(char *string)
{
	int i;
	char *cont;

	for (i = 0; environ[i]; i++)
	{
		cont = strdup(environ[i]);
		cont = strtok(cont, "=");
		if (strcmp(string, cont) == 0)
		{
			cont = strtok(NULL, "=");
			return (cont);
		}
	}
	return (NULL);
}

void printEnv(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
}
int auxCase(char **args)
{
	char *home, *oldpwd, cwd[1024];

	oldpwd = _getenv("PWD");
	home = _getenv("HOME");
	if (strcmp(args[0], "exit") == 0)
		exit(0);
	else if (strcmp(args[0], "env") == 0)
	{
		printEnv();
		return (0);
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
		{
			chdir(home);
			args[1] = home;
		}
		else if (chdir(args[1]) != 0)
			perror("No exist this path");
		if (getcwd(cwd, sizeof(cwd)) == NULL)
			perror("Error");
		_setenv("PWD", cwd);
		_setenv("OLDPWD", oldpwd);
		return (0);
	}
	return (1);
}
