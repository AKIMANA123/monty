#include "monty.h"

/**
 * main - entry point for Monty interpreter
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
FILE *file;
char *line = NULL;
size_t len = 0;
ssize_t read;
unsigned int line_number = 0;
char *opcode, *arg;
stack_t *stack = NULL;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

file = fopen(argv[1], "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

while ((read = getline(&line, &len, file)) != -1)
{
line_number++;
opcode = strtok(line, " \t\n");
if (opcode == NULL || opcode[0] == '#')
continue;

arg = strtok(NULL, " \t\n");

if (strcmp(opcode, "push") == 0)
{
push(&stack, line_number, arg);
}
else if (strcmp(opcode, "pall") == 0)
{
pall(&stack, line_number);
}
else
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
free(line);
fclose(file);
free_stack(stack);
exit(EXIT_FAILURE);
}
}

free(line);
fclose(file);
free_stack(stack);
return (EXIT_SUCCESS);
}
