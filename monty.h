#ifndef BISKIT_MONTY_H
#define BISKIT_MONTY_H

#include <stdio.h>
#include <stdlib.h>
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

/*Function prototypes of stack functions */
void pushi(stack_t **new_node, __attribute__((unused))unsigned int num);
void pall(stack_t **stack, unsigned int line_number);
void pinto(stack_t **stack, unsigned int line_number);
void progErr(int Enum, ...);
void Errmes(int Enum, ...);
void free_mem(void);
stack_t *creator(int n);
void openf(char *file_name);
void reader(FILE *file_ptr);
int tok_input(char *buffer, int line_number, int format);
void fxn_locater(char *opcode, char *opcodeArg, int num, int format);
void popn(stack_t **stack, unsigned int line_number);
void enqueue(stack_t **new_node, __attribute__((unused))unsigned int num);
void caller(exec_func exec, char *opcode, char *opcodeArg, int num, int format);



#endif /* BISKIT_MONTY_H */
