#include "shs.h"

/**
 * _getenv - Finds an enviromental variable.
 *
 * @s: enviromental variable to search.
 * Return: If s is found returns a pointer to the start of the variable
 * otherwise returns NULL.
 */
char *_getenv(char *s)
{
	int i, j;
	char *env;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] == s[j]; j++)
			;
		if (environ[i][j] == '=')
		{
			j++;
			env = malloc((_strlen(&(environ[i][j])) + 1)
				     * sizeof(char));
			_strcpy(env, &(environ[i][j]));
			return (env);
		}
	}
	return (NULL);
}

/**
 * ecodeinit - Initilizes variable to store error codes
 * with 0 on first run
 *
 * @exit_c: pointer to initialize with value of 0
 */
void ecodeinit(char **exit_c)
{
	*exit_c = malloc(4 * sizeof(char));
	(*exit_c)[0] = 0 + '0';
	(*exit_c)[1] = '\0';
}

/**
 * _getpath - checks if user input can be found in the PATH,
 * then stores it
 *
 * @command: command entered by user
 * @envcp: copy of environment
 * Return: 0 if command is found in directory path, -1 otherwise
 */
int _getpath(char **command, char *envcp)
{
	char *env_token = strtok(envcp, ":"), *fullcommand;

	while (env_token != NULL)
	{
		fullcommand = malloc(_strlen(*command) + _strlen(env_token) + 2);
		if (fullcommand == NULL)
			return (-1);

		_strcpy(fullcommand, env_token);
		_strcat(fullcommand, "/");
		_strcat(fullcommand, *command);
		if (access(fullcommand, F_OK) == 0)
		{
			free(*command);
			*command = fullcommand;
			return (0);
		}
		free(fullcommand);
		env_token = strtok(NULL, ":");
	}
	return (-1);
}