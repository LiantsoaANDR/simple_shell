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
	/**
	 * get_input - gets the text from the input
	 * ex_cmd - executes the cmd
	 */
	text = get_input();
	ex_cmd(text, env);
	goto LOOP;

	return (0);
}
