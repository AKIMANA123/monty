#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
int sum;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}

sum = (*stack)->n + (*stack)->next->n;

/* Remove top element */
temp = *stack;
*stack = (*stack)->next;
(*stack)->prev = NULL;
free(temp);

/* Set the new top to the sum */
(*stack)->n = sum;
}
