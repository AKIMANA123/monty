#include "monty.h"

/**
 * queue_mode - sets the format to queue (FIFO)
 * @stack: double pointer to the stack (unused)
 * @line_number: line number in the file (unused)
 */
void queue_mode(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
mode = 1;
}
