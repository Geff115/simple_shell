#include "shell.h"
/**
 * my_command - This function takes the command from the standard input.
 * @my_string: A buffer that stores text read from the standard input.
 *
 * Return: NULL success.
 */
void my_comm(char **my_string, size_t *size)
{
	ssize_t char_str;

	char_str = getline(my_string, size, stdin);
	if (char_str == -1)
	{
		perror("failed to call getline sys call");
		exit(EXIT_FAILURE);
	}
	else if (char_str == 0)
	{
		our_print("\n");
		exit(EXIT_SUCCESS);
	}
}

