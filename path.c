#include "shell.h"
/**
 *
 */
char *find_path(char **env)
{
	char *path;
	unsigned int i = 0;

	while (env[i])
	{
		if (str_cmpf(env[i], "PATH", 4))
			return (env[i]);
		i++;
	}
	return (0);
}
char *find_cmd(char *cmd, char **env)
{
	char *path, char *copy, *token, *cmd_path;
	struct stat buff;
	unsigned int c = 0, t = 0;

	if (stat(cmd, &buff) == 0)
		return (cmd);

	path = find_path(char **env);
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
		token = strtok(copy, ":");
	}
	free(copy);
	return (cmd);

}
int main(int argc, char **argv, char **env)
{
	int i = 0;

	(void)argc;
	(void)argv;

	while (env[i])
	{
		printf("The %d th string is: %s\n", i, env[i]);
		i++;
	}

	return (0);
}
