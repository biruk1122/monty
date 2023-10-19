#include "monty.h"

void pstr_op(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    (void) line_number;

    while (current && current->n > 0 && current->n <= 127)
    {
        printf("%c", current->n);
        current = current->next;
    }
    printf("\n");
}
