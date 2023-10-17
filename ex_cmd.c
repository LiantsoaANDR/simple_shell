#include "shell.h"
/**
 * ex_cmd - executes the cmd asked
 * @text: the text from the input that contains the cmd
 * @env: the environment
 * Return: void
 */
void ex_cmd(char *text, char **env)
{
	char **array, *cmd;
	pid_t child_process;
	int status;

	array = get_cmd(text);

	if (str_cmp(array[0], "exit"))
		exit_cmd(array);

	cmd = find_cmd(array[0], env);
	if (!cmd)
		error_ar(array[0], array);

	child_process = fork();
	if (child_process == -1)
	{
		free(cmd);
		error_ar("fork", array);
	}

	if (child_process == 0)
	{
		if (execve(cmd, array, env) == -1)
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
