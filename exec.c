#include <stdio.h>
#include <unistd.h>

/**
 * _exec - execve example
 * @command: command to be excuted
 * Return: Nothing.
 */
void _exec(void)
{
    char *argv[] = {"/bin/ls", "ls -l", NULL};

    printf("Before execve\n");
    if (execve(argv[0], argv, NULL) == -1)
    {
        perror("Error:");
    }
    printf("After execve\n");
}

