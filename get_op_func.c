#include "monty.h"
/**
 * get_op_func - Get operating function using a two dimension array
 *
 * @cmd: the string to be cmp in the array.
 *
 * Return: the function to be executed
 */
void (*get_op_func(char *cmd))(stack_t **stack, unsigned int line_number)
{
	static instruction_t op[] = {
		{"pall", pall},
		{"pint", pint},
		{"push", push},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i = 0;

	while (i < 8)
	{
		if (strcmp(cmd, op[i].opcode) == 0)
			return (op[i].f);
		i++;
	}
	return (NULL);
}
