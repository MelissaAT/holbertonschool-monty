#include "monty.h"
/**
 * main - Execute the whole monty program
 * 
 * @ac: argument count
 * @av: argument vector
 * 
 * Return: On sucess return 0.
 */
char **tokens = NULL; /* Global Variable */
int main(int ac, char **av)
{
    int input_verification, line_number = 0;
    char *cmd = NULL;
    size_t buffer = 0;
    FILE *fd; /* In order for our getline to send to a file we use this */
    void (*valid_fun)(stack_t **, unsigned int) = NULL;
    stack_t *stack = NULL;

    if (ac != 2)
    {
        dprintf(STDERR_FILENO, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    fd = fopen(av[1], "r"); 
    if (fd == NULL)
    {
        dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
        exit(EXIT_FAILURE);
    }
    while ((input_verification = getline(&cmd, &buffer, fd)) > -1) /* As long as it more then -1 means theres no error */
    {
        line_number++; /* Count the line we have read*/
        tokens = tokenization(cmd, " \n"); /* to check if token is == NULL */
        if (tokens == NULL)
            continue;
        valid_fun = get_op_func(tokens[0]); /* Pair cmd with function*/
        if (valid_fun == NULL)
        {
            dprintf(STDERR_FILENO, "L%d: unknown intruction %s\n", line_number, tokens[0]);
            fclose(fd);
            exit(EXIT_FAILURE);
        }
        valid_fun(&stack, line_number); /* Execute given cmd*/
        buffer = 0;
        free(cmd);
        cmd = NULL;
        free_array(tokens);
        tokens = NULL;
    }
    free_stack(stack);
    free(cmd);
    cmd = NULL;
    fclose(fd);
    fd = NULL;
    exit(EXIT_SUCCESS);
}
