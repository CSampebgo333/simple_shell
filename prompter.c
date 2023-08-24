#include "clement_shell.h"
#include <sys/wait.h>

/**
 * prompter: the variable wich will prompt the argument
 * @argument_count: argument which will be count
 * @environment: the environment which located the argument
 * @string: String that will be prompt
 * @n: counter
 * @i: itinerance
 * @status: To get the staus of the process
 * @number_char: the number of charater contain in the string
 * @arg: the arguments
 */

#define COMMANDE_MAXIMALE 10
void prompter(char **argument_count, char **environment)
{
	char *string = NULL;
	int i, j, status;
	size_t n = 0;
	ssize_t number_char;
	char *argv[COMMANDE_MAXIMALE];
	pid_t id_procesus_enfant;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("cisfun$ ");
		}

		number_char = getline(&string, &n, stdin);
		
		if (number_char == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		i = 0;
		while (string[i])
		{
			if (string[i] == '\n')
			{
				string[i] = 0;
			}
			i++;
		}
		j = 0;
		argv[j] = strtok(string, " ");
		while (argv[j] != NULL)
		{
			j++;
			argv[j] = strtok(NULL, " ");
		}
		
		id_procesus_enfant = fork();
		if (id_procesus_enfant == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		if (id_procesus_enfant == 0)
		{
			if (execve(argv[0], argv, environment) == -1)
			{
				printf("%s: No such file or directory\n", argument_count[0]);
			}
		}
		else
		{
			wait(&status);
		}

	}
}
