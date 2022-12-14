#include "monty.h"
/**
 * nop - doesn't do anything
 * @stack: the list
 * @line_number: line number in the file
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void) stack;
    (void) line_number;
}

/**
 * swap - swap the top two elements of the stack
 * @stack: the list
 * @line_number: line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *cmd;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    cmd = (*stack)->next;
    (*stack)->prev = cmd;
    (*stack)->next = cmd->next;
    cmd->prev = NULL;
    cmd->next = *stack;
    *stack = cmd;
}

/**
 * add - adds the top two elements of the stack
 * @stack: the list
 * @line_number: line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
    stack_t *cmd;

    if (stack == NULL || (*stack)->next == NULL)
    {
        dprintf(STDERR_FILENO, "L%d: cant add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    cmd = *stack;
    cmd->next->n += (*stack)->n;
    *stack = (*stack)->next;
    free(cmd);
    (*stack)->prev = NULL;
}