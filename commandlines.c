#include "shell.h"
/**
 * handle_com_line_args - A function that handles command line with arguments
 * @args: An array of character pointers
 * @new_input: A character pointer.
 *
 * Return: NULL success.
 */
void handle_com_line_args(char *new_input, char *args[])
{
	char *token;
	int c;

	token = strtok(new_input, " ");
	for (c = 0; token != NULL && c < ARG_MAX - 1; c++)
	{
		args[c] = token;
		token = strtok(NULL, " ");
	}
	args[c] = NULL;
}

