#include "main.h"


int main(int argc, char *argv[])
{
	char **args;
	char *buffer = NULL;
	char errorMessage[100];
	int i, l = 0;
	size_t n = 0;
	pid_t pid;

	args = (char **)malloc(sizeof(char *) * argc);
	if (args == NULL)
		return (1);
	for (i = 1; i < argc; i++)
		args[i - 1] = argv[i];

	args[argc - 1] = NULL;
	printf("\n");
	while (1)
	{
		l = 0, n = 0;
		printf("$ ");
		getline(&buffer, &n, stdin);

		while (buffer[i])
			i++;
		if (buffer[i - 1] == '\n')
			buffer[i - 1] = ' ';

		for (i = 0; buffer[i]; i++)
			if (buffer[i] == ' ')
				l++;

		free(args);
		args = (char **)malloc(sizeof(char *) * (l + 1));
		args[0] = strtok(buffer, " ");
		for (i = 1; i < l; i++)
			args[i] = strtok(NULL, " ");
		args[l] = NULL;
		if (strcmp(args[0], "exit") == 0)
			exit(1);
		pid = fork();
		if (pid == 0)
		{
			execvp(args[0], args);
			sprintf(errorMessage, "%s: not found", args[0]);
			perror(errorMessage);
			return (1);
		}
		else if (pid > 0)
		{
			wait(NULL);
			continue;
		}
		else
		{
			perror("error");
		}
	}
	return (0);
}
