#include "shell.h"
/**
 * print_env - prints the env
 * @env: the env to be printed
 * Return: void
 */
void print_env(char **env, char **array)
{
	unsigned int i = 0, j;

	while (env[i])
	{
		for (j = 0; env[i][j];)
			j++;

		write(STDOUT_FILENO, env[i], j);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	free_array(array);

	return;
}
