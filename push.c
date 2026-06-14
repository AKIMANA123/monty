#include "monty.h"

void push(stack_t **stack, unsigned int line_number, char *arg)
{
stack_t *new_node;
stack_t *temp;
int n;

if (arg == NULL || !is_integer(arg))
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}

n = atoi(arg);
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
free_stack(*stack);
exit(EXIT_FAILURE);
}

new_node->n = n;
new_node->prev = NULL;
new_node->next = NULL;

if (mode == 0) /* Stack mode (LIFO) - add to top */
{
new_node->next = *stack;
if (*stack != NULL)
(*stack)->prev = new_node;
*stack = new_node;
}
else /* Queue mode (FIFO) - add to bottom */
{
if (*stack == NULL)
{
*stack = new_node;
}
else
{
temp = *stack;
while (temp->next != NULL)
temp = temp->next;
temp->next = new_node;
new_node->prev = temp;
}
}
}
