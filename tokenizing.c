#include "shell.h"

/**
 * token_count - Count the number of tokens in the string.
 * @command: input string to count
 *
 * Return: umber of tokens found in the input string
 */
int token_count(const char *command)
{
	int counter = 0;
	char *token, *token_cpy;

	token_cpy = strdup(command);

	token = strtok(token_cpy, DELIM);
	while (token)
	{
		counter++;
		token = strtok(NULL, DELIM);
	}

	free(token_cpy);
	return (counter);
}

/**
 * parse_tokens - Parse a string into an array of tokens
 * @command: input string to parse
 * @num_tokens: A pointer to store the number of tokens.
 *
 * Return: rray of tokens (strings) or NULL if fail
 */
char **parse_tokens(char *command, int *num_tokens)
{
	int i = 0;
	char **tokens, *token, *tmp;

	*num_tokens = token_count(command);

	if (*num_tokens == 0)
		return (NULL);

	tokens = (char **) malloc(sizeof(char *) * (*num_tokens + 1));
	if (!tokens)
		return (NULL);

	tokens[*num_tokens] = NULL;

	tmp = strdup(command);
	token = strtok(tmp, DELIM);

	while (token)
	{
		tokens[i] = strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}

	free(tmp);
	return (tokens);
}
