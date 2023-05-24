#include "monty.h"

/**
 * main - Entry point
 * @argc: The number of command line arguments.
 * @argv: The command line arguments.
*/

int stack[STACK_SIZE];
int top = -1;

int main(int argc, char *argv[])
{
FILE *file;
char line[256];
int line_number = 1;
char *opcode, *arg;

if (argc != 2)
{
printf("USAGE: monty %s\n", argv[0]);
exit(EXIT_FAILURE);
}

file = fopen(argv[1], "r");
if (file == NULL) {
printf("Error: Can't open file %s\\n", argv[1]);
exit(EXIT_FAILURE);
}

while (fgets(line, sizeof(line), file) != NULL)
{
line[strcspn(line, "\n")] = '\0';

opcode = strtok(line, " ");
arg = strtok(NULL, " ");

if (opcode != NULL) {
if (strcmp(opcode, "push") == 0)
{
push(line_number, arg);
}
else if (strcmp(opcode, "pall") == 0)
{
pall();
}
else
{
printf("L%d: unknown instruction %s\n", line_number, opcode);
return EXIT_FAILURE;
}
}

line_number++;
}

fclose(file);
return (EXIT_SUCCESS);
}
