#ifndef MONTY_H
#define MONTY_H
#include <stdio.h> /* fopen, dprintf*/
#include <stdlib.h> /* exit, getline, malloc , free  */
#include <unistd.h> /*STDERR_FILENO*/
#include <string.h> /* strcpy, strlen, strtok */
#include <ctype.h> /* isdigit */
extern char **tokens;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd);
} instruction_t;

/* Prototypes Section */
int main(int ac, char **av);
char **tokenization(char *ptr, char *delim);

/* Operation cmd */
void push(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd);
void pall(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd);
void pint(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd);
void pop(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd);
void nop(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd);
void swap(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd);
void add(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd);
void sub(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd);
void _div(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd);
void mul(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd);

/* Function that free */
void free_array(char **tokens);
void free_stack(stack_t *stack);
void reset_inside(char *cmd, char **tokens);

/* Function to combine our cmd with the function */
void (*get_op_func(char *cmd))(stack_t **, unsigned int, char *cmd, FILE *fd);
#endif
