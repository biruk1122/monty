#include "monty.h"


void push_op(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	(void)line_number;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = globals.value;
	new_node->prev = NULL;
	new_node->next = *stack;
	
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}


void pall_op(stack_t **stack, unsigned int line_number)
{
        stack_t *current;
	(void)line_number;

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

void pint_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

void pop_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}


void swap_op(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->prev = NULL;
	if (first->next != NULL)
	{
		first->next->prev = first;
	}
	second->next = first;
	first->prev = second;
	*stack = second;
}
