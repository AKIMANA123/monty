#include "monty.h"

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
else if (strcmp(opcode, "nop") == 0)
{
nop(stack, line_number);
}
else if (strcmp(opcode, "sub") == 0)
{
sub(stack, line_number);
}
else if (strcmp(opcode, "div") == 0)
{
div_op(stack, line_number);
}
else if (strcmp(opcode, "mul") == 0)
{
mul(stack, line_number);
}
else if (strcmp(opcode, "mod") == 0)
{
mod(stack, line_number);
}
else
{
fprintf(stderr, "L%u: unknown instruction %s\n",
line_number, opcode);
free_stack(*stack);
exit(EXIT_FAILURE);
}
}
