#include "monty.h"

/**
 * _pstr - prints the string starting at the top of the stack
 * @stack: double pointer to the head
 * @line_number: current line number
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current != NULL)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}
