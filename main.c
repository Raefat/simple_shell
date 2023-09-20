#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - Entry point of the shell program
 * @argc: number of command-line arguments
 * @argv: array of command-line argument strings
 *
 * Return: Always 0 (success).
 */
int main(int argc, char *argv[])
{
	size_t len = 1024;
	int char_num, num_tokens;
	char *buffer, *filename, **tokens;

	(void) argc;
	filename = argv[0];
	buffer = malloc(sizeof(char) * len);

	while (1)
	{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	char_num = getline(&buffer, &len, stdin);
	if (char_num == -1)
	{
		break;
	}
	tokens = parse_tokens(buffer, &num_tokens);
	if (!tokens)
	continue;

	if (exec_builtins(tokens[0]) == 0)
	{
	free_tokens(tokens, &num_tokens);
	break;
	}
	execute_cmd(tokens, filename, &num_tokens, buffer);
}
	free(buffer);
	return (0);
}

