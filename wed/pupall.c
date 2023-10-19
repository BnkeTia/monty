#include "monty.h"

/**
 * pushi - A function that insert an element to the top of a stack.
 * @stack: Pointer to pointer to the top of the stack.
 * @num: line number of opcode
 */
void pushi(stack_t **stack, unsigned int num)
{
	stack_t *new_node;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - A function that prints all the elements of a stack.
 * @stack: A pointer to a pointer to the top of the stack
 * @num: line number
 */
void pall(stack_t **stack, unsigned int num)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't print from an empty stack\n", num);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
