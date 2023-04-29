#include "main.h"


int _setenv(char *nombre, char *valor)
{
	int i = 0;
	char *env = NULL;

	for (i = 0; environ[i]; i++)
	{
		env = strdup(environ[i]);
		env = strtok(env, "=");
		if (strcmp(env, nombre) == 0)
		{
			environ[i] = NULL;
			environ[i] = malloc(strlen(valor) + strlen(nombre) + 2);
			if (environ[i] == NULL)
				return (1);
			strcat(environ[i], nombre);
			strcat(environ[i], "=");
			strcat(environ[i], valor);
			free(env);
			return (0);
		}
		free(env);
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
	int i = 0;

	if (array == NULL)
		return;
	for (i = 0; array[i]; i++)
		free(array[i]);
	free(array);
}

char **cutString(char *input)
{
	int len = 0;
	char **cutStr = NULL, *copy_input = NULL, *token = NULL;

	if (input == NULL)
		return (NULL);

	copy_input = strdup(input);
	token = strtok(copy_input, " \n\t");
	if (token == NULL)
	{
		free(copy_input);
		return (NULL);
	}
	for (len = 0; token; len++)
		token = strtok(NULL, " \n\t");
	free(copy_input);
	cutStr = (char **)malloc(sizeof(char *) * (len + 1));
	if (cutStr == NULL)
		return (NULL);

	copy_input = strdup(input);
	token = strtok(copy_input, " \n\t");
	for (len = 0; token; len++)
	{
		cutStr[len] = strdup(token);
		token = strtok(NULL, " \n\t");
	}
	cutStr[len] = NULL;
	free(copy_input);
	return (cutStr);
}

