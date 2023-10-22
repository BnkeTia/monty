#include "monty.h"

/**
 * pchar - A function that prints the char at the top of the stack.
 * @stack: Pointer to a pointer to top node of the stack.
 * @line_number: line number.
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		stringer(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		stringer(10, line_number);
	printf("%c\n", ascii);
}

/**
 * pstr - A function that prints a string starting from the top.
 * @stack: Pointer to a pointer to top node of the stack.
 * @ln: line number.
 * Return: void.
 */
void pstr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - A function that rotates the stack to the top
 * @stack: Pointer to a pointer to top node of the stack.
 * @ln: line number.
 * Return: void
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - A function that rotates the stack to the bottom.
 * @stack: Pointer to a pointer to top node of the stack.
 * @ln: line number.
 * Return: void.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
