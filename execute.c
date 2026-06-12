#include "monty.h"

/**
 * execute_opcode - executes the given opcode
 * @opcode: opcode to execute
 * @arg: argument for the opcode
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */
void execute_opcode(char *opcode, char *arg, stack_t **stack,
		    unsigned int line_number)
{
	if (strcmp(opcode, "push") == 0)
	{
		push(stack, line_number, arg);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, opcode);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
