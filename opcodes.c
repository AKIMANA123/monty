#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 * @arg: argument value
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
stack_t *new_node;
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
new_node->next = *stack;

if (*stack != NULL)
(*stack)->prev = new_node;

*stack = new_node;
}

/**
 * pall - prints all values on the stack
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
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

/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */
void pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}

temp = *stack;
*stack = (*stack)->next;
if (*stack != NULL)
(*stack)->prev = NULL;
free(temp);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
int temp;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}

temp = (*stack)->n;
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = temp;
}

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

temp = *stack;
*stack = (*stack)->next;
(*stack)->prev = NULL;
free(temp);

(*stack)->n = sum;
}
