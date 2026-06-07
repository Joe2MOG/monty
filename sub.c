#include "monty.h"

/**
 * _sub - subtracts the top element from the second top element
 * @stack: double pointer to the head of the stack
 * @line_number: current line number
 *
 * Description: The result is stored in the second top element,
 * and the top element is removed.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}
