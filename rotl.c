#include "monty.h"

/**
 * _rotl - rotates the stack to the top
 * @stack: double pointer to the head
 * @line_number: current line number
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	top = *stack;
	*stack = top->next;
	(*stack)->prev = NULL;

	bottom = *stack;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->next = top;
	top->prev = bottom;
	top->next = NULL;
}
