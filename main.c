#include "main.h"


int main(int __attribute__((unused)) ac, char **av)
{
	char **args = NULL, *input = NULL, *check = NULL, *error = NULL;
	size_t n = 0;
	int status = 0;

		signal(SIGINT, contr);
		while (1)
		{
			if (isatty(0) == 1)
				printf("$ ");
			if (getline(&input, &n, stdin) == -1 || strcmp(input, "exit\n") == 0)
			{
				if (input)
					free(input);
				exit(status);
			}
			args = cutString(input);
			if (args == NULL || auxCase(args) == 0)
				;
			else
			{
				check = _which(args[0]);
				if (check)
				{
					args[0] = strdup(check);
					status = execCom(args);
				}
				else
				{
					status = 127;
					error = malloc(strlen(av[0]) + strlen(args[0]) + 18);
					sprintf(error, "%s: 1: %s: not found\n", av[0], args[0]);
					perror(error);
					free(error);
				}
				free(check);
			}
			free_array(args);
		}
		free(input);
	return (status);
}
