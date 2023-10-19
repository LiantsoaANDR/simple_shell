#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

extern char **environ;

/*free and exit functions*/
void free_array(char **array);
void error_ar(char *msg, char **array);
void exit_cmd(char **array);

/*string functions*/
int is_space(char *string);
char *_strdup(char *string);
int str_cmp(char *first, char *second);
int str_cmpf(char *first, char *second, unsigned int nbr);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

/*PATH and env functions*/
char *find_path(void);
char *find_cmd(char *cmd);
void print_env(char **array);

char *get_input(void);
char **get_cmd(char *text);
void ex_cmd(char *text);

#endif
