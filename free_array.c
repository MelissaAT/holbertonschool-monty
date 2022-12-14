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
 * @head: pointer to the start of the list
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}