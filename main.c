#include "shell.h"
/**
 * main - acts like a simple shell
 * Return: 0 on success
 */
int main(void)
{
	char *text;

LOOP:
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "($) ", 4);
	text = get_input();
	if (*text == '\0' || is_space(text))
	{
		free(text);
		goto LOOP;
	}

	ex_cmd(text);
	goto LOOP;

	return (0);
}
