#include "shell.h"
#include <string.h>
/**
 * find_path - finds the PATH in the env
 * Return: the PATH as a string
 */
char *find_path(void)
{
	unsigned int i = 0;

	while (environ[i])
	{
		if (str_cmpf(environ[i], "PATH", 4))
			return (environ[i]);
		i++;
	}
	return (0);
}
/**
 * find_cmd - finds the right diresctory into PATH
 * @cmd: the cmd given the search into PATH
 * Return: the full path of the cmd asked
 * If we did not find any match, return the given cmd
 */
char *find_cmd(char *cmd)
{
	char *path = NULL, *copy = NULL;
	char *token = NULL, *cmd_path = NULL;
	struct stat buff;
	unsigned int c = 0, t = 0;

	while (cmd[c])
		c++;
	if (stat(cmd, &buff) == 0)
	{
		cmd_path = _strdup(cmd);
		return (cmd_path);
	}
	path = find_path();
	if (!path)
		return (NULL);

	copy = _strdup(path);
	token = strtok(copy, ":");
	while (token)
	{
		for (t = 0; token[t];)
			t++;
		cmd_path = malloc(sizeof(char) * (c + t + 2));
		_strcpy(cmd_path, token);
		_strcat(cmd_path, "/");
		_strcat(cmd_path, cmd);
		_strcat(cmd_path, "\0");
		if (stat(cmd_path, &buff) == 0)
		{
			free(copy);
			return (cmd_path);
		}
		free(cmd_path);
		token = strtok(NULL, ":");
	}
	free(copy);
	return (NULL);
}
