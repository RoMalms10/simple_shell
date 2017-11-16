#include "holberton1.h"

/**
 * get_pid - Returns a pid.
 *
 * Return: A process ID number.
 */
pid_t get_pid(void)
{
    my_pid = getpid();
    return (my_pid);
}

/**
 * get_ppid - Returns a ppid.
 *
 * Return: A process ID number.
 */
pid_t get_ppid(void)
{
        pid_t my_ppid;
        my_ppid = getppid();
        return (my_ppid);
}
