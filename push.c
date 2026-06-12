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
 * push_with_arg - pushes an element to the stack with given argument
 * @stack: double pointer to the stack
 * @arg: argument value
 * @line_number: line number in the file
 */
void push_with_arg(stack_t **stack, char *arg, unsigned int line_number)
{
stack_t *new_node;
int n;

(void)line_number;

n = atoi(arg);
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = n;
new_node->prev = NULL;
new_node->next = *stack;

if (*stack != NULL)
(*stack)->prev = new_node;

*stack = new_node;
}
