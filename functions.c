#include "monty.h"
/**
 * push - pushes an element to the stack
 * @stack: the list
 * @line_number: line number in the file
 * @cmd: string from getline
 * @fd: File set as the upstream of getline
 */
void push(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd)
{
	stack_t *new_node = NULL;

	if (stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push interger\n", line_number);
		free(new_node);
		free(cmd);
		free_array(tokens);
		free_stack(*stack);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL || tokens[1] == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push interger\n", line_number);
		free(new_node);
		free(cmd);
		free_array(tokens);
		free_stack(*stack);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	if (isdigit(*tokens[1]) == 0) /* Ckecks if its a number */
	{
		dprintf(STDERR_FILENO, "L%d: usage: push interger\n", line_number);
		free(new_node);
		free(cmd);
		free_array(tokens);
		free_stack(*stack);
		fclose(fd);
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
 * @cmd: string from getline
 * @fd: File set as the upstream of getline
 */
void pall(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd)
{
	(void) line_number;
	(void) cmd;
	(void) fd;
	stack_t *tmp = NULL;

	if (stack == NULL || *stack == NULL)
		return;

	tmp = *stack;

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
 * @cmd: string from getline
 * @fd: File set as upstream of getline
 */
void pint(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd)
{
	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		free_array(tokens);
		free(cmd);
		free_stack(*stack);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: the list
 * @line_number: line number in the file
 * @cmd: string from getline
 * @fd: File set as upstream of getline
 */
void pop(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd)
{
	stack_t *tmp = NULL;

	if (*stack == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		free_array(tokens);
		free(cmd);
		free_stack(*stack);
		fclose(fd);
		exit(EXIT_FAILURE);
	}

	if (stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: the list
 * @line_number: line number in the file
 * @cmd: string from getline
 * @fd: file set as upstream of getline
 */
void mul(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line_number);
		free_array(tokens);
		free(cmd);
		free_stack(*stack);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number, cmd, fd);
}
