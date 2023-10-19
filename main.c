#include "shell.h"
/**
 * main - acts like a simple shell
 * @argc: argument count
 * @argv: argument vector
 * @env: environment
 * Return: 0 on success
 */
int main(int argc, char **argv, char **env)
{
	char *text;

	(void)argc;
	(void)argv;

LOOP:
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "($) ", 4);
	text = get_input();
	if (*text == '\0' || is_space(text))
	{
		free(text);
		goto LOOP;
	}

	ex_cmd(text, env);
	goto LOOP;

	return (0);
}
