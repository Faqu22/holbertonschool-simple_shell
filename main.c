#include "main.h"


int main(void)
{
	char **args;
	char *input = NULL, *check = NULL;
	int i, l;
	size_t n = 0;

	printf("\n");
	while (1)
	{
		l = 0;
		if (isatty(0) == 1)
			printf("$ ");
		getline(&input, &n, stdin);
		if (strcmp(input, "\n") == 0)
			continue;
		for (i = 0; input[i]; i++)
			if (input[i] == ' ')
				l++;
		if (input[i - 1] == '\n')
			input[i - 1] = '\0';
		args = (char **)malloc(sizeof(char *) * (l + 1));
		if (args == NULL)
			return (1);
		args[0] = strtok(input, " ");
		for (i = 1; i < l + 1; i++)
			args[i] = strtok(NULL, " ");
		args[l + 1] = NULL;
		if (strcmp(args[0], "exit") == 0)
			exit(1);
		if (strcmp(args[0], "env") == 0)
			printEnv();
		else if (_which(args[0]))
		{
			check = _which(args[0]);
			args[0] = check;
			execCom(args);
		}
		free(args);
		continue;
	}
	return (0);
}
