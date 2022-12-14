#include "monty.h"
/**
 * 
 *  
 * 
 */
void *push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    return(NULL);

new_node->n = line_number;
new_node->prev = NULL;
new_node->next = *stack;

if (*stack != NULL)
    (*stack)->prev = new_node;

*stack = new_node;
}

void pall(const stack_t *stack)
{
    int count = 0;

while (stack != NULL)
{
    printf("%d\n", stack->n);
    stack = stack->next;
}
}
void pint(stack_t **stack, unsigned int line_number)
{
    stack_t *cmd = *stack;
    if (cmd = NULL)
        dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);

    printf("%d\n", *cmd->n);
}

void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *cmd;
	int data;

	if (*stack == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack", line_number);
        exit(EXIT_FAILURE);
	}
	else
	{
		cmd = (*stack)->next;
        *stack = cmd;
        cmd = cmd->prev;
        (*stack)->prev = NULL;
        free(cmd);
    }
}
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *cmd;

    if (*stack == NULL || stack == NULL)
 {
   	    dprintf(STDERR_FILENO, "L%d: can't pop an empty stack", line_number);
        exit(EXIT_FAILURE); 
 }
 cmd = (*stack)->next;
 (*stack)->prev = cmd;
 (*stack)->next = cmd->next;
 cmd->prev = NULL;
 cmd->next = *stack;
 *stack = cmd;
}

void add(stack_t **stack, unsigned int line_number)
{
 if (*stack == NULL || stack == NULL)
 {
   	    dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE); 
 }
}   