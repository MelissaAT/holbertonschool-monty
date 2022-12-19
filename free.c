#include "monty.h"
/**
 * free_array - function to free a array
 * @tokens: array to be free
 * Return: Theres no return. (void)
 */
void free_array(char **tokens)
{
	int i = 0;

	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}

	free(tokens);
}

#include "monty.h"
/**
 * free_stack - function that frees a list
 * @stack: pointer to the start of the list
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = tmp->next;
		free(tmp);
	}
}

#include "monty.h"
/**
 * reset_inside - function is at the end of the loop to reset everything
 * @cmd: cmd that we get from getline
 * @tokens: two dimension array
 */
void reset_inside(char *cmd, char **tokens)
{
	free(cmd);
	free_array(tokens);
}
