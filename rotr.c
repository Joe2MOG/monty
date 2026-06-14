#include "monty.h"

/**
 * _rotr - rotates the stack to the bottom
 * @stack: double pointer to the head
 * @line_number: current line number
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *bottom;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	bottom = *stack;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	bottom->prev = NULL;
	bottom->next = *stack;
	(*stack)->prev = bottom;
	*stack = bottom;
}
