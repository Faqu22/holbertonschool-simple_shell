#include "main.h"

int execCom(char **args)
{
	int status = 0;

	if (fork() == 0)
	{
		execve(args[0], args, environ);
		perror("error pa");
	}
	else
		wait(&status);
	return (WEXITSTATUS(status));
}

char *_getenv(char *string);

char *_which(char *args)
{
	char *list;
	char *comm;
	char *path;

	list = _getenv("PATH");
	if (strchr(args, '/'))
	{
		free(list);
		return (args);
	}
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
	free(comm);
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
