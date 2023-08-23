#include <stdio.h>
#include <unistd.h>

/**
 * _pid - PID
 * Return: Nothing.
 */
void _pid(void)
{
    pid_t my_pid;

    my_pid = getpid();
    printf("%u\n", my_pid);
}

