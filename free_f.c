#include "shell.h"
/**
 * free_array - frees an array of string
 * @array: the array to be freed
 * Return: void
 */
void free_array(char **array)
{
	unsigned int i = 0;

	if (!array)
		return;

	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
	}

	free(array);
	array = NULL;
}
