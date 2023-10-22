#include "monty.h"

/**
 * fxn_locater - A function that locate required function.
 * @opcode: opcode
 * @opcodeArg: opcode argument
 * @num: line number
 * @format: format of arguments
 * Return: void.
 */
void fxn_locater(char *opcode, char *opcodeArg, int num, int format)
{
	int found_match, x;

	instruction_t locater_list[] = {
		{"push", pushi},
		{"pall", pall},
		{"pint", pinto},
		{"pop", popn},
		{"swap", swapn},
		{"add", addxn},
		{"nop", nop},
		{"sub", sub},
		{NULL, NULL}
	};
	if (opcode[0] == '#')
		return;
	for (found_match = 1, x = 0; locater_list[x].opcode != NULL; x++)
	{
		if (strcmp(opcode, locater_list[x].opcode) == 0)
		{
			caller(locater_list[x].f, opcode, opcodeArg, num, format);
			found_match = 0;
		}
	}
	if (found_match == 1)
		progErr(3, num, opcode);
}
/**
 * openf - A function that opens a file.
 * @file_name: namepath of the file.
 * Return: void
 */
void openf(char *file_name)
{
	FILE *file_ptr = fopen(file_name, "r");

	if (file_name == NULL || file_ptr == NULL)
		progErr(2, file_name);

	reader(file_ptr);
	fclose(file_ptr);
}

/**
 * reader - A function that reads a file
 * @file_ptr: A pointer to the file.
 * Return: void
 */
void reader(FILE *file_ptr)
{
	int line_number = 0;
	int format = 0;
	char *buffer = NULL;
	size_t lengt = 0;

	for (line_number = 1; getline(&buffer, &lengt, file_ptr) != -1; line_number++)
	{
		format = tok_input(buffer, line_number, format);
	}
	free(buffer);
}
/**
 * tok_input - A function that tokenizes each line to call functions.
 * @buffer: tokenize file lines into individual elements.
 * @line_number: line number
 * @format: format of commands, determines how to process commands.
 * Return: 0 on success
 */
int tok_input(char *buffer, int line_number, int format)
{
	char *opcode;
	char *opcodeArg = NULL;
	const char *toker = "\n";

	if (buffer == NULL)
		progErr(4);
	opcode = strtok(buffer, toker);
	if (opcode == NULL)
		return (format);
	opcodeArg = strtok(NULL, toker);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	fxn_locater(opcode, opcodeArg, line_number, format);

	return (format);
}
