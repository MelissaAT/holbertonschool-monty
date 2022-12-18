#include "monty.h"
/**
 * get_op_func - Get operating function using a two dimension array
 *
 * @cmd: the string to be cmp in the array.
 *
 * Return: the function to be executed
 */
void (*get_op_func(char *cmd))(stack_t **, unsigned int, char *, FILE *)
{
	static instruction_t op[] = {
		{"pall", pall},
		{"pint", pint},
		{"push", push},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"div", _div},
		{"sub", sub},
		{"mul", mul},
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
