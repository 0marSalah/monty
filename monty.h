#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE

#include <stdio.h> /* File, fopen, getline, fclose, stderr */
#include <stdlib.h> /* EXIT_SUCCESS, EXIT_FAILURE, free */
#include <unistd.h> /* isatty, write, STDIN_FILENO */
#include <ctype.h> /* isdigit */
#include <sys/types.h> /* ssize_t */
#include <string.h> /* strtok, strcmp */

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


typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;

int execute(char *content, stack_t **head, unsigned int line_number,
FILE *file);
void push(stack_t **head, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
void free_stack(stack_t *head);
void add_node(stack_t **head, int n);
void pint(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void fadd(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void sub(stack_t **head, unsigned int line_number);
void fdiv(stack_t **head, unsigned int line_number);
void mul(stack_t **head, unsigned int line_number);
void mod(stack_t **head, unsigned int line_number);

#endif
