#include "shell.h"
/**
 * our_print - This function prints to the standard output.
 * @message: A string to be printed to stdout.
 *
 * Return: Always 0 success.
 */
void our_print(const char *message)
{
	write(STDOUT_FILENO, message, strlen(message));
}

