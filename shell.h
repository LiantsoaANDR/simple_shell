#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>

/*free functions*/
void free_array(char **array);

/*string functions*/
int is_space(char *string);
char *_strdup(char *string);

char *get_input(void);
char **get_cmd(char *text);
void ex_cmd(char *text, char **env);

#endif
