#include "monty.h"

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

	read_file(file_ptr);
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
	size_t length = 0;

	for (line_number = 1; getline(&buffer, &length, fd) != -1; line_number++)
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
	char *opcode, param;
	const char *toker = "\n";

	if (buffer == NULL)
		progErr(4);
	opcode = strtok(buffer, toker);
	if (opcode == NULL)
		return (format);
	param = strtok(NULL, toker);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	fxn_locater(opcode, param, line_number, format);
	return (format);
}
