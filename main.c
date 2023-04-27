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
			printf("(auxCase I)\n");
			if (auxCase(args) == 0)
				printf("(auxCase 0)\n");
			else
			{
				printf("(which I)\n");
				check = _which(args[0]);
				printf("(which O)\n");
				if (check)
				{
					args[0] = strdup(check);
					printf("[hola]\n");
					execCom(args);
					free(check);
					printf("[funciono]\n");
				}
				else
					perror("Error with which");
			}
			free_array(args);
			printf("free O\n");
			if (isatty(0) != 1)
				break;
		}
	return (0);
}
