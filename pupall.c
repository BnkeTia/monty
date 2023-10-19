#include "monty.h"

/**
 * pushi - A function that insert an element to the top of a stack.
 * @new_node: Pointer to pointer to the new node top of the stack.
 * @num: line number of opcode
 */
void pushi(stack_t **new_node, __attribute__((unused))unsigned int num)
{
	stack_t *temp, *head;

	if (stack == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}

/**
 * pall - A function that prints all the elements of a stack.
 * @stack: A pointer to a pointer to the top of the stack
 * @num: line number
 */
void pall(stack_t **stack, unsigned int num)
{
	stack_t *temp;
	(void) num;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * popn - A function that removes an element from a stack.
 * @stack: pointer to a pointer to the top of the stack
 * @num: line number
 */
void popn(stack_t **stack, unsigned int num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		Errmes(7, num);
	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
