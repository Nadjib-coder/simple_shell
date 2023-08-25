#include "shell.h"

/**
 * split_input - a function that Split the input line
 * into a command and its arguments.
 * @input: the user input
 * @cmd_args: command arguments
 * Return: nothing.
 */
void split_input(char *input, char *cmd_args[])
{
	char *token = strtok(input, " \t");
	int arg_count = 0;

	while (token != NULL)
	{
		cmd_args[arg_count] = token;
		arg_count++;
		token = strtok(NULL, " \t");
	}
	cmd_args[arg_count] = NULL;
}

