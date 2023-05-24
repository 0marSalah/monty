#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @line_number: int
 * @arg: char
*/

void push(int line_number, char *arg) {
    int value;

    if (arg == NULL)
    {
        printf("L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(arg);

    if (top < STACK_SIZE - 1)
    {
        top++;
        stack[top] = value;
    }
    else
    {
        printf("L%d: Stack overflow\n", line_number);
        exit(EXIT_FAILURE);
    }
}
