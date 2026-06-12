#include "monty.h"

/**
 * process_line - processes a single line of the bytecode file
 * @line: line read from file
 * @line_number: current line number
 * @stack: double pointer to the stack
 */
void process_line(char *line, unsigned int line_number, stack_t **stack)
{
char *opcode, *arg;

opcode = strtok(line, " \t\n");
if (opcode == NULL || opcode[0] == '#')
return;

arg = strtok(NULL, " \t\n");
execute_opcode(opcode, arg, stack, line_number);
}
