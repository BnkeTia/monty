#include "monty.h"

/**
 * opener - A function that opens a file
 * @file_name: the file namepath
 * Return: void
 */

void opener(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		progErr(2, file_name);

	reader(fd);
	fclose(fd);
}


/**
 * reader - A function that reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void reader(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = parser(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * parser - A function that separates each line into tokens.
 * @buffer: line from the file
 * @line_number: line number
 * @format:  format.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parser(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		progErr(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	loc(opcode, value, line_number, format);
	return (format);
}

/**
 * loc - A function that locates the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format: format
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void loc(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pinto},
		{"pop", pop},
		{"nop", nop},
		{"swap", swapn},
		{"add", addxn},
		{"sub", subxn},
		{"div", divxn},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			caller(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		progErr(3, ln, opcode);
}


/**
 * caller - A function that calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format
 * if 1 nodes will be entered as a queue.
 */
void caller(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			progErr(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				progErr(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
