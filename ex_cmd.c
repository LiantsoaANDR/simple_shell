#include "shell.h"
/**
 * ex_cmd - executes the cmd asked
 * @text: the text from the input that contains the cmd
 * @env: the environment
 * Return: void
 */
void ex_cmd(char *text, char **env)
{
	char **array;
	pid_t child_process;
	int status;

	array = get_cmd(text);

	if (str_cmp(array[0], "exit"))
		exit_cmd(array);

	child_process = fork();
	if (child_process == -1)
	{
		perror("fork");
		free_array(array);
		exit(EXIT_FAILURE);
	}
	if (child_process == 0)
	{
		if (execve(array[0], array, env) == -1)
		{
			perror(array[0]);
			free_array(array);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		free_array(array);
	}
}
