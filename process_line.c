#include "monty.h"

void process_line(char *line, unsigned int line_number, stack_t **stack)
{
char *opcode, *arg;

opcode = strtok(line, " \t\n");
if (opcode == NULL || opcode[0] == '#')
return;

arg = strtok(NULL, " \t\n");
execute_opcode(opcode, arg, stack, line_number);
}
