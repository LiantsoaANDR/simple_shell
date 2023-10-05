#include "shell.h"
#include <string.h>
/**
 * get_cmd - gets the cmd from the input
 * @text: the text read from the input
 * Return: pointer to an array of string which contains the cmd
 */
char **get_cmd(char *text)
{
	char **array, *delim = " \n", *copy, *token;
	unsigned int arrc = 0, i = 0;

	copy = _strdup(text);
	token = strtok(text, delim);
	while (token)
	{
		token = strtok(NULL, delim);
		arrc++;
	}
	free(text);

	array = malloc(sizeof(char *) * (arrc + 1));
	if (!array)
	{
		free(copy);
		exit(EXIT_FAILURE);
	}

	token = strtok(copy, delim);
	while (token)
	{
		array[i] = _strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	array[i] = NULL;
	free(copy);
	return (array);
}
