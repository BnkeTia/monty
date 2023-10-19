#include "monty.h"

/**
 * pinto - A function that prints a stack
 * @stack: A pointer to a pointer to the top
 * @num: line number
 */
void pinto(stack_t **stack, unsigned int num)
{
	if (stack == NULL || *stack == NULL)
		Errmes(6, num);
	printf("%d\n", (*stack)->n);
}

/**
 * Errmes - A function that prints error messages
 * @Enum: respective error numbers
 * (7): cannot pint cus stack is empty.
 * (8): stack is short.
 */
void Errmes(int Enum, ...)
{
	va_list bagu;
	int numA;
	char *com;

	va_start(bagu, Enum);
	switch (Enum)
	{
		case 7:
			fprintf(stderr, "L%d: empty stack can't pint\n", va_arg(bagu, int));
			break;
		case 8:
			numA = va_arg(bagu, unsigned int);
			com = va_arg(bagu, char*);
			fprintf(stderr, "L%d: %s, short stack\n", numA, com);
			break;
		default:
			break;
	}
	free_mem();
	exit(EXIT_FAILURE);
}
