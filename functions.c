#include "monty.h"
/**
 * push - pushes an element to the stack
 * @stack:
 * @line_number: line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node = NULL;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        dprintf(STDERR_FILENO, "L%d: usage: push interger", line_number);
        exit(EXIT_FAILURE);
    }
    new_node-> n = atoi(tokens[1]);
    new_node->next = *stack;
    new_node->prev = NULL;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;

}

/**
 * pall - prints all the values on the stack, starting from the top of the stack
 * @stack:
 * @line_number: line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
    (void) line_number;
    stack_t *cmd = *stack;

    while (cmd != NULL)
    {
        printf("%d\n", (*cmd).n);
        cmd = (*cmd).next;
    }
}

/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @stack:
 * @line_number: line number in the file
 */
void pint(stack_t **stack, unsigned int line_number)
{
    stack_t *cmd = *stack;

    if (cmd == NULL)
    {
        dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*cmd).n);
}

/**
 * pop - removes the top element of the stack
 * @stack:
 * @line_number: line number in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *cmd;

    if (*stack == NULL)
    {
        dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    
    if ((*stack)->next == NULL)
    {
        free(*stack);
        *stack = NULL;
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