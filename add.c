#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @stack: double pointer to the head
 * @line_number: current line number
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}
