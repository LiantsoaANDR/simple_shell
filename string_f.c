#include "shell.h"
/**
 * _strdup - duplicate a string
 * @string: the string to be duplicated
 * Return: the duplicated string, 0 if @string is NULL
 */
char *_strdup(char *string)
{
	int i = 0;
	char *new;

	if (!string)
		return (0);

	while (string[i])
		i++;

	new = malloc((i + 1) * sizeof(char));
	if (!new)
		return (0);

	for (i = 0; string[i]; i++)
		new[i] = string[i];
	new[i] = '\0';

	return (new);
}
