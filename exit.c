#include "shell.h"
/**
 * exit_cmd - exits all process when we write 'exit'
 * @array: the array of arguments from the input
 * Return: void
 */
void exit_cmd(char **array)
{
	int code = 0;

	if (array[1])
		code = _atoi(array[1]);

	if (code < 0)
		code = -1;

	free_array(array);
	exit(code);
}
/**
 * error_ar - output an error message then free an array and exit
 * @msg: the error message
 * @array: the array
 */
void error_ar(char *msg, char **array)
{
	perror(msg);
	free_array(array);
	exit(EXIT_FAILURE);
}
