#include "shell.h"
#include <unistd.h>

/**
 * exec_builtins - Executes the shell command commands.
 * @command: command we wanna execute.
 *
 * Return: 0 when d command is "exit," and 1 otherwise
 */
int exec_builtins(char *command)
{
	int i;

	if (_strcmp(command, "exit") == 0)
	{
		return (0);
	}
	else if (_strcmp(command, "env") == 0)
	{
		for (i = 0; environ[i]; i++)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		}
	return (1);
}

/**
 * execute_cmd - Executes the commands.
 * @commands:array of command arguments we entered
 * @filename: name of shell program.
 * @num_tokens: number of tokens in the cmd
 * @buffer: input buffer
 *
 * Return: 0 on success, 1 on failure
 */
int execute_cmd(char **commands, char *filename, int *num_tokens, char *buffer)
{
int my_pid, status;
char *full_path;

full_path = get_matched_path(commands[0]);
if (!full_path)
{
	perror(filename);
	free_tokens(commands, num_tokens);
	free(full_path)
	return (1);
}

my_pid = fork();
if (my_pid == -1)
	perror("fork");
else if (my_pid == 0)
{
	if (execve(full_path, commands, environ) == -1)
	{
		free(buffer);
		free_tokens(commands, num_tokens);
	}
}
else
{
	waitpid(my_pid, &status, 0);
	free_tokens(commands, num_tokens);
	free(full_path);
}
}

