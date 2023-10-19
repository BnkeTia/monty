#include "monty.h"

/**
* main - Entry point to the code.
* Return: 0 on success
*/
int main(void)
{
    stack_t *stack = NULL;
    unsigned int line_number = 1;

    pushi(&stack, 10);
    pushi(&stack, 20);
    pushi(&stack, 30);

    pall(&stack, line_number);

    return (0);
}
