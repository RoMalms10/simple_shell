#include "holberton1.h"

/**
 * ignore_c - Function that ignores the signalhandler for ctrl+c
 *
 * @signum: The number indicating SIGINT (Always 2)
 *
 * Return: 2 if successfully ignored, SIG_ERR otherwise
 */
sighandler_t ignore_c(int signum)
{
	sighandler_t handler;

	/* Returns value of sighandler (2), ot SIG_ERR on error */
	handler = signal(signum, SIG_IGN);
	return (handler);
}
