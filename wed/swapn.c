#include "monty.h"

/**
 * swapn - A function that swaps the top two elements of the stack.
 * @stack: pointer to a pointer to the top of the stack
 * @line_number: line number
 * Return: void.
 */
void swapn(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		Errmes(8, line_number, "swap");
	temp = (*stack)->next;

	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = NULL;
	temp->prev = NULL;
	*stack = temp;
}
/**
 * addxn - A function that adds the top two elements of the stack.
 * @stack: pointer to a pointer to the top
 * @line_number: line number
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
 * nop - A lazy function that does not do anything.
 * @stack: pointer to a pointer to the top of the stack
 * @line_number: line number
 * Return: void.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * sub - A function tha subtracts the top elements from the second element.
 * @stack: pointer to a pointer to the top of the stack.
 * @line_number: line number
 * Return: void.
 */
void sub(stack_t **stack, unsigned int line_number)
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
