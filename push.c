#include "monty.h"

/**
 * is_integer - checks if a string is an integer
 * @str: string to check
 *
 * Return: 1 if integer, 0 otherwise
 */
int is_integer(char *str)
{
int i = 0;

if (str == NULL || str[0] == '\0')
return (0);

if (str[0] == '-')
i = 1;

for (; str[i] != '\0'; i++)
{
if (!isdigit(str[i]))
return (0);
}
return (1);
}

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
