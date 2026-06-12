#include "monty.h"

/**
 * execute_opcode - executes the given opcode
 * @opcode: opcode to execute
 * @arg: argument for the opcode
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */
void execute_opcode(char *opcode, char *arg, stack_t **stack, unsigned int line_number)
{
if (strcmp(opcode, "push") == 0)
{
if (arg == NULL || !is_integer(arg))
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
push_with_arg(stack, arg, line_number);
}
else if (strcmp(opcode, "pall") == 0)
{
pall(stack, line_number);
}
else
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}
}
