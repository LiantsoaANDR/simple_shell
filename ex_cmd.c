#include "shell.h"
/**
 * ex_cmd - executes the cmd asked
 * @text: the text from the input that contains the cmd
 * Return: void
 */
void ex_cmd(char *text)
{
	char **array = NULL, *cmd = NULL;

	array = get_cmd(text);
	if (str_cmp(array[0], "exit"))
		exit_cmd(array);

	if (str_cmp(array[0], "env"))
	{
		print_env(array);
		return;
	}

	cmd = find_cmd(array[0]);
	if (!cmd)
	{
		perror(array[0]);
		free_array(array);
		return;
	}

	executer(cmd, array);
}
/**
 * executer - executes the verified cmd
 * @cmd: the verified cmd
 * @array: the array that contains the cmd
 * Return: void
 */
void executer(char *cmd, char **array)
{
	pid_t child_process;
	int status;

	child_process = fork();
	if (child_process == -1)
	{
		free(cmd);
		error_ar("fork", array);
	}
	if (child_process == 0)
	{
		if (execve(cmd, array, environ) == -1)
		{
			free(cmd);
			error_ar(array[0], array);
		}
	}
	else
	{
		wait(&status);
		free_array(array);
		free(cmd);
	}
}
