#include "main.h"


int _setenv(char *nombre, char *valor)
{
	int i;
	char *env;

	for (i = 0; environ[i]; i++)
	{
		env = strdup(environ[i]);
		env = strtok(env, "=");
		if (strcmp(env, nombre) == 0)
		{
			environ[i] = NULL;
			environ[i] = malloc(sizeof(char *) * (strlen(valor) + strlen(nombre) + 1));
			if (environ[i] == NULL)
				return (1);
			environ[i] = env;
			strcat(environ[i], "=");
			strcat(environ[i], valor);
			return (0);
		}
	}
	return (1);
}
void contr(int a)
{
	signal(a, SIG_IGN);
	printf("\n");
	if (isatty(0) == 1)
		printf("$ ");
	fflush(stdout);
	signal(a, contr);
}

void free_array(char **array)
{
	int i;

	for (i = 0; array[i]; i++)
		free(array[i]);
	free(array);
}
