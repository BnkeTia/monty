#include <stdio.h>
#include <stdlib.h>

typedef union data_u
{
    int integer;
    char character;

} data_t;

typedef struct stack_s
{
    data_t data;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

void push(stack_t **stack, data_t data);
void pall(stack_t **stack, unsigned int line_number);

int main(void)
{
    stack_t *stack = NULL;
    unsigned int line_number = 1;

    data_t data1, data2, data3;
    data1.integer = 10;
    data2.character = 'A';
    data3.character = 'B';

    push(&stack, data1);
    push(&stack, data2);
    push(&stack, data3);

    pall(&stack, line_number);

    return 0;
}

void push(stack_t **stack, data_t data)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
    {
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't print from an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    while (current != NULL)
    {
        if (current->data.integer)
            printf("%d\n", current->data.integer);
        else
            printf("%c\n", current->data.character);

        current = current->next;
    }
}
