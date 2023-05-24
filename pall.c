#include "monty.h"

/**
 * pall - Prints all the values on the stack, 
 * starting from the top of the stack.
*/

void pall() {
    int i;

    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}