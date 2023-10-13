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
/**
 * is_space - checks if there is only space in a string
 * @string: the string to look into
 * Return: 0 if false and 1 if true
 */
int is_space(char *string)
{
	unsigned int i = 0;

	while (string[i])
	{
		if (string[i] != ' ')
			return (0);
		i++;
	}

	return (1);
}
/**
 * str_cmp - compares if all the char of two strings are the same
 * @first: the first string
 * @second: the second string
 * Return: 0 if false and 1 if true
 */
int str_cmp(char *first, char *second)
{
	unsigned int i = 0;

	while (first[i] && second[i])
	{
		if (first[i] != second[i])
			return (0);
		i++;
	}

	if ((!first[i] && second[i]) || (first[i] && !second[i]))
		return (0);

	return (1);
}
