#include "monty.h"

/**
 * nop - A lazy function that does nothing.
 * @stack: Pointer to a pointer to top node of the stack.
 * @line_number: line number.
 * Return: void.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * swapn - A function that swaps the top two elements of the stack.
 * @stack: Pointer to a pointer to the top node of the stack.
 * @line_number: line number.
 * Return: void.
 */
void swapn(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		Errmes(8, line_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * addxn - A function that adds the top two elements of the stack.
 * @stack: Pointer to a pointer to top node of the stack.
 * @line_number: line number.
 * Return: void.
 */
void addxn(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		Errmes(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * subxn - A function that subracts the top two elements of the stack.
 * @stack: Pointer to a pointer to top node of the stack.
 * @line_number: line number
 * Return: void.
 */
void subxn(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		Errmes(8, line_number, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * divxn - A function that divides the 2nd top element by the top element..
 * @stack: Pointer to a pointer to the top node of the stack.
 * @line_number: line number
 * Return: void.
 */
void divxn(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		Errmes(8, line_number, "div");

	if ((*stack)->n == 0)
		Errmes(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
