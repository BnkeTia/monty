#include "monty.h"


/**
 * push - A function that adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: line number.
 * Return: void.
 */
void push(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * pall - A function that prints the stack.
 * @stack: Pointer to a pointer to the top of the stack.
 * @line_number: line number.
 * Return: void.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop - A function that removes a node from the stack.
 * @stack: Pointer to a pointer to the top of the stack.
 * @line_number: line number.
 * Return: void.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		Errmes(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * pinto - A function that prints the value at the top of the stack.
 * @stack: Pointer to a pointer to the top node of the stack.
 * @line_number: line number.
 * Return: void.
 */
void pinto(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		Errmes(6, line_number);
	printf("%d\n", (*stack)->n);
}
