#include "monty.h"

/**
 * pint - prints top element
 * @stack: stack
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr,
			"L%u: can't pint, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop_op - removes top element
 * @stack: stack
 * @line_number: line number
 */
void pop_op(stack_t **stack, unsigned int line_number)
{
        stack_t *temp;

        if (*stack == NULL)
        {
                fprintf(stderr,
                        "L%u: can't pop an empty stack\n",
                        line_number);
                exit(EXIT_FAILURE);
        }

        temp = *stack;
        *stack = (*stack)->next;

        if (*stack)
                (*stack)->prev = NULL;

        free(temp);
}

/**
 * swap - swaps top two elements
 * @stack: stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
        int temp;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr,
                        "L%u: can't swap, stack too short\n",
                        line_number);
                exit(EXIT_FAILURE);
        }

        temp = (*stack)->n;
        (*stack)->n = (*stack)->next->n;
        (*stack)->next->n = temp;
}

/**
 * add - adds top two elements
 * @stack: stack
 * @line_number: line number
 */
void add(stack_t **stack, unsigned int line_number)
{
        int sum;
        stack_t *temp;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr,
                        "L%u: can't add, stack too short\n",
                        line_number);
                exit(EXIT_FAILURE);
        }

        sum = (*stack)->n + (*stack)->next->n;

        temp = *stack;
        *stack = (*stack)->next;
        (*stack)->prev = NULL;
        (*stack)->n = sum;

        free(temp);
}

/**
 * nop - does nothing
 * @stack: stack
 * @line_number: line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * div_op - divides second top by top
 * @stack: stack
 * @line_number: line number
 */
void div_op(stack_t **stack, unsigned int line_number)
{
        int result;
        stack_t *temp;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr,
                        "L%u: can't div, stack too short\n",
                        line_number);
                exit(EXIT_FAILURE);
        }

        if ((*stack)->n == 0)
        {
                fprintf(stderr,
                        "L%u: division by zero\n",
                        line_number);
                exit(EXIT_FAILURE);
        }

        result = (*stack)->next->n / (*stack)->n;

        temp = *stack;
        *stack = (*stack)->next;
        (*stack)->prev = NULL;
        (*stack)->n = result;

        free(temp);
}

/**
 * mul - multiplies top two elements
 * @stack: stack
 * @line_number: line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
        int result;
        stack_t *temp;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr,
                        "L%u: can't mul, stack too short\n",
                        line_number);
                exit(EXIT_FAILURE);
        }

        result = (*stack)->n * (*stack)->next->n;

        temp = *stack;
        *stack = (*stack)->next;
        (*stack)->prev = NULL;
        (*stack)->n = result;

        free(temp);
}

/**
 * sub - subtracts the top element from the second top element
 * @stack: stack
 * @line_number: line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
    int result;
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    result = (*stack)->next->n - (*stack)->n;

    temp = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    (*stack)->n = result;

    free(temp);
}

/**
 * mod_op - computes the rest of the division of the second top by top element
 * @stack: stack
 * @line_number: line number
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
    int result;
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    result = (*stack)->next->n % (*stack)->n;

    temp = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    (*stack)->n = result;

    free(temp);
}

/**
 * pstr - prints string from stack
 * @stack: stack
 * @line_number: line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
        stack_t *current;

        (void)line_number;

        current = *stack;

        while (current)
        {
                if (current->n <= 0 || current->n > 127)
                        break;

                printf("%c", current->n);
                current = current->next;
        }

        printf("\n");
}

/**
 * pchar - prints char at top of stack
 * @stack: stack
 * @line_number: line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
        if (*stack == NULL)
        {
                fprintf(stderr,
                        "L%u: can't pchar, stack empty\n",
                        line_number);
                exit(EXIT_FAILURE);
        }

        if ((*stack)->n < 0 || (*stack)->n > 127)
        {
                fprintf(stderr,
                        "L%u: can't pchar, value out of range\n",
                        line_number);
                exit(EXIT_FAILURE);
        }

        printf("%c\n", (*stack)->n);
}

/**
 * rotl - rotates stack left
 * @stack: stack
 * @line_number: line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
        stack_t *head, *tail;

        (void)line_number;

        if (*stack == NULL || (*stack)->next == NULL)
                return;

        head = *stack;
        tail = *stack;

        while (tail->next)
                tail = tail->next;

        *stack = head->next;
        (*stack)->prev = NULL;

        tail->next = head;
        head->prev = tail;
        head->next = NULL;
}

/**
 * rotr - rotates stack right
 * @stack: stack
 * @line_number: line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
        stack_t *tail;

        (void)line_number;

        if (*stack == NULL || (*stack)->next == NULL)
                return;

        tail = *stack;

        while (tail->next)
                tail = tail->next;

        tail->prev->next = NULL;
        tail->prev = NULL;
        tail->next = *stack;
        (*stack)->prev = tail;
        *stack = tail;
}
