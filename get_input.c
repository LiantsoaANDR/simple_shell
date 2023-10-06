#include "shell.h"
/**
 * get_input - read the text from the input
 * Return: the text as a string
 */
char *get_input(void)
{
	char *text = NULL;
	size_t size = 0;
	ssize_t read = 0;

	read = getline(&text, &size, stdin);
	if (read == -1)
	{
		free(text);
		exit(EXIT_FAILURE);
	}
	return (text);
}
