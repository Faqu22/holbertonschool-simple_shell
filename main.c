#include "main.h"


int main(void)
{
	char **args = NULL, *input = NULL, *check = NULL;
	size_t n = 0;

		signal(SIGINT, contr);
		while (1)
		{
			if (isatty(0) == 1)
				printf("$ ");
			getline(&input, &n, stdin);
			args = cutString(input);
			if (auxCase(args) == 0)
				;
			else
			{
				check = _which(args[0]);
				if (check)
				{
					args[0] = strdup(check);
					execCom(args);
					free(check);
				}
				else
					perror("Error with which");
			}
			free_array(args);
			if (isatty(0) != 1)
				break;
		}
	return (0);
}
