#include "shell.h"
#include <string.h>
/**
 * find_path - finds the PATH in the env
 * @env: the env
 * Return: the PATH as a string
 */
char *find_path(char **env)
{
	unsigned int i = 0;

	while (env[i])
	{
		if (str_cmpf(env[i], "PATH", 4))
			return (env[i]);
		i++;
	}
	return (0);
}
/**
 * find_cmd - finds the right diresctory into PATH
 * @cmd: the cmd given the search into PATH
 * @env: the env
 * Return: the full path of the cmd asked
 * If we did not find any match, return the given cmd
 */
char *find_cmd(char *cmd, char **env)
{
	char *path, *copy,*token, *cmd_path;
	struct stat buff;
	unsigned int c = 0, t = 0;

	if (stat(cmd, &buff) == 0)
		return (cmd);

	path = find_path(env);
	if (!path)
		return (0);

	while (cmd[c])
		c++;

	copy = _strdup(path);
	token = strtok(copy, ":");

	while (token)
	{
		for (t = 0; token[t];)
			t++;
		cmd_path = malloc(c + t + 2);

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

	return (0);

}
