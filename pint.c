#include "monty.h"

/**
 * pint: prints the value at the top of the stack
 * @head: stack head
 * @line_number: line_number
 * Return: no return
 */

void pint(stack_t **head, unsigned int line_number)
{
  stack_t *h;

  h = *head;
  if (h == NULL)
  {
    fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
    fclose(bus.file);
    free(bus.content);
    free_stack(*head);
    exit(EXIT_FAILURE);
  }
  printf("%d\n", h->n);
}
