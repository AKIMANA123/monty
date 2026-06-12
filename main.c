#include "monty.h"

/**
 * open_file - opens the bytecode file
 * @filename: name of the file to open
 *
 * Return: file pointer
 */
FILE *open_file(char *filename)
{
FILE *file;

file = fopen(filename, "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
exit(EXIT_FAILURE);
}
return (file);
}

/**
 * read_and_execute - reads and executes lines from file
 * @file: file pointer
 * @stack: double pointer to the stack
 */
void read_and_execute(FILE *file, stack_t **stack)
{
char *line = NULL;
size_t len = 0;
ssize_t read;
unsigned int line_number = 0;

while ((read = getline(&line, &len, file)) != -1)
{
line_number++;
process_line(line, line_number, stack);
}
free(line);
}

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
stack_t *stack = NULL;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

file = open_file(argv[1]);
read_and_execute(file, &stack);
fclose(file);
free_stack(stack);
return (EXIT_SUCCESS);
}
