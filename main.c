#include "monty.h"
/**
 * main - Execute the whole monty program
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: On sucess return 0.
 */
char **tokens = NULL; /* Global Variable */
int main(int ac, char **av)
{
	int input_verification, line_number = 0;
	char *cmd = NULL;
	size_t buffer = 0;
	FILE *fd; /* In order for our getline to send to a file we use this */
	void (*valid_fun)(stack_t **, unsigned int, char *, FILE *) = NULL;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((input_verification = getline(&cmd, &buffer, fd)) > -1)
	{
		line_number++; /* Count the line we have read*/
		if (strcmp(cmd, "\n") == 0 || *cmd == '#')
			continue;
		tokens = tokenization(cmd, " \n");
		if (tokens == NULL)
		{
			free(tokens);
			continue;
		}
		valid_fun = get_op_func(tokens[0]); /* Pair cmd with function*/
		valid_fun(&stack, line_number, cmd, fd); /* Execute given cmd*/
		buffer = 0;
		reset_inside(cmd, tokens);
		cmd = NULL;
		tokens = NULL;
	}
	free(cmd);
	free_stack(stack);
	fclose(fd);
	exit(EXIT_SUCCESS);
}
