#include "monty.h"

/**
 * execute_opcode - finds and calls the opcode function
 * @stack: double pointer to the stack
 * @line_num: current line number
 * @opcode: opcode string
 * @instr: array of instruction_t structures
 */
void execute_opcode(stack_t **stack, unsigned int line_num,
		    char *opcode, instruction_t *instr)
{
	int i;

	for (i = 0; instr[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instr[i].opcode) == 0)
		{
			instr[i].f(stack, line_num);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * main - Monty bytecode interpreter
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int argc, char **argv)
{
	FILE *file;
	char line[1024];
	unsigned int line_num = 0;
	stack_t *stack = NULL;
	char *opcode, *arg;
	instruction_t instr[] = {
		{"pall", _pall}, {"pint", _pint}, {"pop", _pop},
		{"swap", _swap}, {"add", _add}, {"sub", _sub},
		{"mod", _mod}, {"div", _div}, {"mul", _mul},
		{"nop", _nop}, {NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file HoLbErToN\n");
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_num++;
		opcode = strtok(line, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, " \t\n");
			_push(&stack, line_num, arg);
			continue;
		}
		execute_opcode(&stack, line_num, opcode, instr);
	}
	free_stack(stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
