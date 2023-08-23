#include "clement_shell.h"

/**
 * @argument_count: argument wich will be count
 * @argument_vector: argument vector
 * @environment: the environment which located the argu
ment
 */
int main(int argument_count, char **argument_vector, char **environment)
{
	if (argument_count == 1)
	{
		prompter(argument_vector, environment);
		return (0);
	}
	return (1);
}
