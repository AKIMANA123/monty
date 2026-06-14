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
 * process_line - processes a single line of the bytecode file
 * @line: line read from file
 * @line_number: current line number
 * @stack: double pointer to the stack
 */
void process_line(char *line, unsigned int line_number, stack_t **stack)
{
char *opcode, *arg;
char *line_copy;
int i = 0;

/* Skip leading spaces/tabs */
while (line[i] == ' ' || line[i] == '\t')
i++;

/* Check if line is a comment (starts with #) */
if (line[i] == '#')
return;

line_copy = line + i;
opcode = strtok(line_copy, " \t\n");
if (opcode == NULL)
return;

arg = strtok(NULL, " \t\n");
execute_opcode(opcode, arg, stack, line_number);
}
