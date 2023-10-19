#include "monty.h"

/**
 * main - Point of entry for this fine code
 * @argc: number of arguments
 * @argv: argument list
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	openf(argv[1]);
	free_mem();
	return (0);
}
/**
 * creator - A function that creates a new node.
 * @n: integer value of node.
 * Return: node address or pointer to the node or NULL on failure.
 */
stack_t *creator(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		progErr(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}
/**
 * enqueue - A function that adds a node to a queue
 * @new_node: pointer to a pointer to the new node
 * @num: line number.
 */
void enqueue(stack_t **new_node, __attribute__((unused))unsigned int num)
{
	stack_t *temp, head;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *new_node;
	(*new_node)->prev = temp;
}
