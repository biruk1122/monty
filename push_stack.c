#include "monty.h"
<<<<<<< HEAD


void push_op(stack_t **stack)/*unsigned int line_number*/
=======
/**
 * push_op - pushing a value
 * @stack: stack
 * @line_number: line number
 */
/*void push_op(stack_t **stack, unsigned int line_number)
>>>>>>> 28f109157040416f2fea5fde4b736aeed0d167e2
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
		*stack = new_node;
	}
}*/
void push_op(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	(void)line_number;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = globals.value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

<<<<<<< HEAD

void pall_op(stack_t **stack)/*unsigned int line_number*/
=======
/**
 * pall_op - pall
 * @stack: stack
 * @line_number: line
 */
void pall_op(stack_t **stack, unsigned int line_number)
>>>>>>> 28f109157040416f2fea5fde4b736aeed0d167e2
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * pint_op - pint
 * @stack: stack
 * @line_number: line
 */
void pint_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop_op - pop
 * @stack: stack
 * @line_number: line
 */
void pop_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
<<<<<<< HEAD
	temp = *stack;
=======

>>>>>>> 28f109157040416f2fea5fde4b736aeed0d167e2
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
<<<<<<< HEAD
	/*stack_t *temp = *stack;*/
=======

	temp = *stack;
>>>>>>> 28f109157040416f2fea5fde4b736aeed0d167e2
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}
/**
 * swap_op - swap
 * @stack: stack
 * @line_number: line
 */

void swap_op(stack_t **stack, unsigned int line_number)
{
<<<<<<< HEAD
	stack_t *second;
	stack_t *first;
	first = *stack;
	second = first->next;
=======
	stack_t *first;
	stack_t *second;

>>>>>>> 28f109157040416f2fea5fde4b736aeed0d167e2
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
<<<<<<< HEAD
	/*stack_t *first = *stack;*/
	/*stack_t *second = first->next;*/
=======
	first = *stack;
	second = first->next;
>>>>>>> 28f109157040416f2fea5fde4b736aeed0d167e2
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
