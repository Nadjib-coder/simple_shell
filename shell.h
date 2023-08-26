#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

/* function declaration */
void split_input(char *input, char *cmd_args[]);
void execute_command(const char *prg_name, char *const args[], int cmd_num);
int command_exists(const char *command);
void print_environment(void);
extern char **environ;

#endif
