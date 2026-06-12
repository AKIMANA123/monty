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

temp = *stack;
*stack = (*stack)->next;
(*stack)->prev = NULL;
free(temp);

(*stack)->n = sum;
}

/**
 * nop - does nothing
 * @stack: double pointer to the stack (unused)
 * @line_number: line number in the file (unused)
 */
void nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}

/**
 * sub - subtracts the top element from the second top element
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */
void sub(stack_t **stack, unsigned int line_number)
{
int result;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}
result = (*stack)->next->n - (*stack)->n;
pop(stack, line_number);
(*stack)->n = result;
}

/**
 * mul - multiplies the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */
void mul(stack_t **stack, unsigned int line_number)
{
int result;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}
result = (*stack)->next->n * (*stack)->n;
pop(stack, line_number);
(*stack)->n = result;
}

/**
 * div_op - divides the second top element by the top element
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */
void div_op(stack_t **stack, unsigned int line_number)
{
int result;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}
if ((*stack)->n == 0)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}
result = (*stack)->next->n / (*stack)->n;
pop(stack, line_number);
(*stack)->n = result;
}

/**
 * mod - computes the remainder of the division of the second top element
 *       by the top element
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */
void mod(stack_t **stack, unsigned int line_number)
{
int result;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}
if ((*stack)->n == 0)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
free_stack(*stack);
exit(EXIT_FAILURE);
}
result = (*stack)->next->n % (*stack)->n;
pop(stack, line_number);
(*stack)->n = result;
}
