#ifndef BISKIT_MONTY_H
#define BISKIT_MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void opener(char *file_name);
int parser(char *buffer, int line_number, int format);
void reader(FILE *);
int len_chars(FILE *);
void loc(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node(int n);
void free_mem(void);
void pall(stack_t **, unsigned int);
void push(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);

void caller(op_func, char *, char *, int, int);

void pinto(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swapn(stack_t **, unsigned int);

/*Math operations with nodes*/
void addxn(stack_t **, unsigned int);
void subxn(stack_t **, unsigned int);
void divxn(stack_t **, unsigned int);
void mul_nodes(stack_t **, unsigned int);
void mod_nodes(stack_t **, unsigned int);

/*String operations*/
void print_char(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/*Error hanlding*/
void progErr(int error_num, ...);
void Errmes(int error_num, ...);
void stringer(int error_num, ...);
void rotr(stack_t **, unsigned int);

#endif /* BISKIT_MONTY_H */
