#include "monty.h"

/**
 * progErr - A function that controls and prints the errors
 * @Enum: Error numbers of the respective errors
 * (1): no file or not more than one file is given by user.
 * (2): file cannot be opened or read.
 * (3): file contains invalid instruction.
 * (4): cannot malloc anymore
 * (5): if push parameter is not an int.
 * (6): empty stack for pop..
 */
void progErr(int Enum, ...)
{
	va_list bagu;
	int numA;
	char *com;

	va_start(bagu, Enum);
	switch (Enum)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(bagu, char*));
			break;
		case 3:
			numA = va_arg(bagu, int);
			com = va_arg(bagu, char *);
			fprintf(stderr, "L%d: unknown insruction %s\n", numA, com);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: NOT AN INTEGER\n", va_arg(bagu, int));
			break;
		case 6:
			fprintf(stderr, "L%d: stack is empty, can't pop\n", va_arg(bagu, int));
		default:
			break;
	}
	free_mem();
	exit(EXIT_FAILURE);
}

/**
 * caller - A function that calls the needed function
 * @exec: a pointer to the function next in call line.
 * @opcode: opcode string
 * @opcodeArg: value
 * @num: line number
 * @format: format
 * Return: void.
 */
void caller(exec_func exec, char *opcode, char *opcodeArg, int num, int format)
{
	stack_t *new_node;
	int found_match, x;
	stack_t *head = NULL;

	found_match = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (opcodeArg != NULL && opcodeArg[0] == '-')
		{
			opcodeArg = opcodeArg + 1;
			found_match = -1;
		}
		if (opcodeArg == NULL)
			progErr(5, num);
		for (x = 0; opcodeArg[x] != '\0'; x++)
		{
			if (isdigit(opcodeArg[x]) == 0)
				progErr(5, num);
		}
		new_node = creator(atoi(opcodeArg) * found_match);
		if (format == 0)
			exec(&new_node, num);
		if (format == 1)
			enqueue(&new_node, num);
	}
	else
	{
		exec(&head, num);
	}
}
