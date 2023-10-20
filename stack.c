#include "monty.h"
/**
 * free_stack - to make free
 * @stack: data struchure
 */
void free_stack(stack_t *stack)
{

	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}
}
