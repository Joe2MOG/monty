#include "monty.h"

/**
 * _pall - prints all values on the stack from top
 * @stack: double pointer to the head
 * @line_number: unused line number
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
