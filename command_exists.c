#include "shell.h"

/**
 * command_exists - a function that check if a
 * command exists and is executable.
 * @command: the command to check
 * Return: 1 if the command exists and is executable,
 * 0 otherwise.
 */
int command_exists(const char *command)
{
	return (access(command, X_OK) == 0);
}

