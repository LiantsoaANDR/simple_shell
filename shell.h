#ifndef _SHELL_H_
#define _SHELL_H_

char *get_input(void);
char **get_cmd(char *text);
void ex_cmd(char **array, char **env);

#endif
