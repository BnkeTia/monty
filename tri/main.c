#include "monty.h"

stack_t *head = NULL;

/**
 * main - entry point of the function
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	opener(argv[1]);
	free_mem();
	return (0);
}

/**
 * create_node - A function that creates a node.
 * @n: Number to go inside the node.
 * Return: a pointer to the node. Otherwise NULL.
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
 * free_mem - A function that frees nodes in the stack.
 * Return: void.
 */
void free_mem(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * enqueue - A function that adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number
 */
void enqueue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;

}
