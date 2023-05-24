#include "main.h"

/**
 * main - the main executing funtion
 * Return: interactive or nonn interactive
 */

int main(void)
{
	if (isatty(STDIN_FILENO))
	{
		run_interactive_shell();
	}
	else
	{
		run_non_interactive_shell();
	}
	return (0);
}

/**
 * run_interactive_shell - run interactive part of shell
 * Return: inffinite command
 */

void run_interactive_shell(void)
{
	char input[MAX_INPUT_SIZE];
	char **commands;
	int i;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 10);
		read_input(input);
		if (input[0] == '\0')
			continue;
		commands = split_input_by_semicolon(input);
		for (i = 0; commands[i] != NULL; i++)
			execute_command(commands[i]);
		free(commands);
	}
}

/**
 * run_non_interactive_shell - the function that runs the non-interactive part
 * Return -execute command ones
 */
void run_non_interactive_shell(void)
{
	char input[MAX_INPUT_SIZE];
	char **commands;
	int i;

	read_input(input);
	commands = split_input_by_semicolon(input);
	for (i = 0; commands[i] != NULL; i++)
	{
		execute_command(commands[i]);
	}
	free(commands);
}

/**
 * read_input - getting the user input
 * @input: user input
 * Return: strings of user input
 */

void read_input(char *input)
{
	size_t bufferSize = MAX_INPUT_SIZE;
	ssize_t bytesRead = getline(&input, &bufferSize, stdin);

	if (bytesRead != -1)
		input[strcspn(input, "\n")] = '\0';
}

/**
 * split_input_by_semicolon - split iinput by column
 * @input: input
 * Return: charactreer pointer
 */
char **split_input_by_semicolon(const char *input)
{
	char *input_copy = _strdup(input);
	char **commands = malloc((strlen(input) + 1) * sizeof(char *));
	char *token = _strtok(input_copy, ";");
	int i = 0;

	while (token != NULL)
	{
		commands[i] = _strdup(token);
		token = _strtok(NULL, ";");
		i++;
	}
	commands[i] = NULL;
	free(input_copy);
	return (commands);
}
