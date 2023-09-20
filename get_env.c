#include "shell.h"

/**
 * full_path_maker - Creates a path.
 * @path: directory path
 * @command: command to append to the path
 *
 * Return: the allocated string containing the whole path
 */
char *full_path_maker(const char *path, const char *command)
{
	char *full_path;
	unsigned int size;

	size = _strlen(path) + _strlen(command) + 2;

	full_path = malloc(sizeof(char) * size);
	_strcpy(full_path, path);
	_strcat(full_path, "/");
	_strcat(full_path, command);
	return (full_path);
}

/**
 * get_paths - Get the path variable
 *
 * Return: pointer to the PATH variable.
 */
char *get_paths()
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], "PATH=", 5) == 0)
			return (environ[i] + 5);
	}
	return (NULL);
}

/**
 * is_command_path - Checks if a command contains the path
 * @command: command to check.
 *
 * Return: 1 if the command contains the path, 0 otherwise
 */
int is_command_path(const char *command)
{
	int i = 0;
	struct stat st;

	while (command[i])
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return (1);
		}
	i++;
	}
	return (0);
}

/**
 * get_matched_path - Find the path of a command.
 * @command: The command to locate
 *
 * Return: allocated string containing the full path if found, or NULL
 */
char *get_matched_path(const char *command)
{
	const char *paths;
	char *token, *tmp, *full_path;
	struct stat st;

	if (is_command_path(command))
		return (_strdup(command));
	paths = get_paths();
	tmp = _strdup(paths);
	token = strtok(tmp, ":");
	if (paths)
	{
		while (token)
		{
		full_path = full_path_maker(token, command);
		if (stat(full_path, &st) == 0)
		{
			free(tmp);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
		}
	}
	free(tmp);
	return (NULL);
}

