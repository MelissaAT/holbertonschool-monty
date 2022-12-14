#include "monty.h"
/**
 * main - 
 * @ac:
 * @av:
 * Return:
 */
int main (int ac, char **av)
{
    int count, input_verification, line_number, num = 0;
    char *cmd = NULL, **tokens = NULL;
    size_t buffer = 0;
    FILE *fd;
    void(*valid_fun)(stack_t **, unsigned int);
    if (ac != 2)
    {
        dprintf(STDERR_FILENO, "USAGE: monty file \n");
        exit(EXIT_FAILURE);
    }
    fd = fopen(av[1], "r");
    if (fd == -1)
    exit(EXIT_FAILURE);
    {
        dprintf(STDERR_FILENO, "error: can't open file %s\n", av[1]);
    }
    while ((input_verification = getline(&cmd, buffer, fd)) > -1)
    {
        line_number++;
        tokens = tokenization(cmd, " \n");
        valid_fun = get_op_func(tokens[0]);
        num = atoi(token[1]);
        if (valid_fun == NULL)
        {   
            dprintf(STDERR_FILENO, "L%D: unknown instruction%S\n", line_number, tokens[0]);
            fclose(fd);
            exit(EXIT_FAILURE);
        }

    }
    exit(EXIT_SUCCESS);
}

