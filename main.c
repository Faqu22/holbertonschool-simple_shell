#include "main.h"


int main(void)
{
	char **args;
	char *input = NULL, *check = NULL;
	int i, l;
	size_t n = 0;

		signal(SIGINT, contr);
		while (1)
		{
			l = 0;
			if (isatty(0) == 1)
				printf("$ ");
			getline(&input, &n, stdin);
			if (strcmp(input, "\n") == 0)
				continue;
			for (i = 0; input[i]; i++)
				if (input[i] == '\n' || input[i] == '\t' || input[i] == ' ')
				{
					input[i] = ' ';
					l++;
				}
			input[i - 1] = '\0';
			args = (char **)malloc(sizeof(char *) * l);
			if (args == NULL)
				return (1);
			args[0] = strtok(input, " ");
			for (i = 1; i < l; i++)
				args[i] = strtok(NULL, " ");
			args[l] = NULL;
			if (auxCase(args) == 0)
				;
			else if (_which(args[0]))
			{
				check = _which(args[0]);
				args[0] = check;
				execCom(args);
			}
			else
				perror("ERROR");
			if (issaty(0) != 1)
				break;
			free(args);
			continue;
		}
	return (0);
}
