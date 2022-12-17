#include "monty.h"
/**
 * nop - doesn't do anything
 * @stack: the list
 * @line_number: line number in the file
 */
void nop(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd)
{
	(void) stack;
	(void) line_number;
	(void) cmd;
	(void) fd;
}

/**
 * swap - swap the top two elements of the stack
 * @stack: the list
 * @line_number: line number in the file
 */
void swap(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		exit_free(*stack, cmd, fd);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	(*stack)->prev = tmp;
	(*stack)->next = tmp->next;
	tmp->prev = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

/**
 * add - adds the top two elements of the stack
 * @stack: the list
 * @line_number: line number in the file
 */
void add(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd)
{
	stack_t *tmp;

	if (stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: cant add, stack too short\n", line_number);
		exit_free(*stack, cmd, fd);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp->next->n += (*stack)->n;
	*stack = (*stack)->next;
	free(tmp);
	(*stack)->prev = NULL;
}
