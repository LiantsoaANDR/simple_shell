#include "shell.h"
/**
 * exit_cmd - exits all process when we write 'exit'
 * @array: the array of arguments from the input
 * Return: void
 */
void exit_cmd(char **array)
{
	write(STDOUT_FILENO, "exit\n", 5);

	if (array[1])
	{
		perror(array[1]);
	}

	free_array(array);

	exit(EXIT_SUCCESS);
}
