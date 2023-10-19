#include "monty.h"
/**
 * get_op_func - get op
 * @opcode: opcode
 * Return: get the op
 */
void (*get_op_func(char *opcode))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pint", pint_op},
		{"pop", pop_op},
		{"swap", swap_op},
		{"add", add_op},
		{"nop", nop_op},
		{NULL, NULL}
	};

	while (ops[i].opcode != NULL)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
