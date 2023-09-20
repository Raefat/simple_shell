#include "shell.h"
/**
 * free_tokens - Frees memory allocated for the array
 * @tokens: array of tokens to free
 * @num_tokens: The number of tokens in that array.
 *
 */

void free_tokens(char **tokens, int *num_tokens)
{
	int i;

	for (i = 0; i <= *num_tokens; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}

/*printf("%s || ", tokens[i]);*/

