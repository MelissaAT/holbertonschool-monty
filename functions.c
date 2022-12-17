#include "monty.h"
/**
 * push - pushes an element to the stack
 * @stack: the list
 * @line_number: line number in the file
 */
void push(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push interger\n", line_number);
		exit_free(*stack, cmd, fd);
		free(new_node);
		exit(EXIT_FAILURE);
	}

	if (tokens[1] == NULL) /* Checks if theres is a second argument */
	{
		dprintf(STDERR_FILENO, "L%d: usage: push interger\n", line_number);
		exit_free(*stack, cmd, fd);
		free(new_node);
		exit(EXIT_FAILURE);
	}
	if (isdigit(*tokens[1]) == 0) /* Ckecks if its a number */
	{
		dprintf(STDERR_FILENO, "L%d: usage: push interger\n", line_number);
		exit_free(*stack, cmd, fd);
		free(new_node);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(tokens[1]); /* Convert the number to a interger */
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;

}

/**
 * pall - prints all the values on the stack
 * @stack: the list
 * @line_number: line number in the file
 */
void pall(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd)
{
	(void) line_number;
	(void) cmd;
	(void) fd;
	stack_t *tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", (*tmp).n);
		tmp = (*tmp).next;
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @stack: the list
 * @line_number: line number in the file
 */
void pint(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd)
{
	stack_t *tmp = *stack;

	if (tmp == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit_free(*stack, cmd, fd);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*tmp).n);
}

/**
 * pop - removes the top element of the stack
 * @stack: the list
 * @line_number: line number in the file
 */
void pop(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		exit_free(*stack, cmd, fd);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		tmp = (*stack)->next;
		*stack = tmp;
		tmp = tmp->prev;
		(*stack)->prev = NULL;
		free(tmp);
	}

}
