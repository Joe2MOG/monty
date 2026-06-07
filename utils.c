#include "monty.h"

/**
 * _isdigit_str - checks if a string contains only digits (with leading '-')
 * @s: string to check
 *
 * Return: 1 if valid integer, 0 otherwise
 */
int _isdigit_str(char *s)
{
	int i = 0;

	if (s == NULL || *s == '\0')
		return (0);
	if (s[0] == '-')
		i++;
	for (; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * free_stack - frees a doubly linked list
 * @stack: pointer to the top of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
