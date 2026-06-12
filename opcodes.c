#include "monty.h"

/**
 * push - pushes value onto stack
 * @stack: stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int value;
	int i = 0;

	if (argument == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	if (argument[0] == '-')
		i = 1;

	while (argument[i])
	{
		if (!isdigit(argument[i]))
		{
			fprintf(stderr,
				"L%u: usage: push integer\n",
				line_number);
			exit(EXIT_FAILURE);
		}
		i++;
	}

	value = atoi(argument);

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - prints all stack values
 * @stack: stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
