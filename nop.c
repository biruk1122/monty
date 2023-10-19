#include "monty.h"
void add_op(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *temp;
	temp = *stack;
	result = (*stack)->n + (*stack)->next->n;
	
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*int result = (*stack)->n + (*stack)->next->n;*/
	/*stack_t *temp = *stack;*/
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
	(*stack)->n = result;
}

void nop_op(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
