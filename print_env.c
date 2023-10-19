#include "shell.h"
/**
 * print_env - prints the env
 * @array: array to be freed
 * Return: Nothing
 */
void print_env(char **array)
{
	unsigned int i = 0, j;

	while (environ[i])
	{
		for (j = 0; environ[i][j];)
			j++;

		write(STDOUT_FILENO, environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	free_array(array);
}
