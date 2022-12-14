#include "monty.h"
/**
 * 
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
