#include "monty.h"

int mode = 0; /* 0 = stack (LIFO), 1 = queue (FIFO) */

/**
 * _stack - sets the format to stack (LIFO)
 * @stack: unused
 * @line_number: unused
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	mode = 0;
}

/**
 * _queue - sets the format to queue (FIFO)
 * @stack: unused
 * @line_number: unused
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	mode = 1;
}
