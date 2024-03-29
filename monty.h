#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>

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

/**
 * struct var_s - variables
 * @lifi: stack or queue
 * @arg: value
 * @fd: file descripter
 * @cont: content of the line
 *
 * Description: holds value through the prog
 */
typedef struct var_s
{
	int lifi;
	char *arg;
	FILE *fd;
	char *cont;
} var_t;
extern var_t var;
/* stack1.c*/
void f_pint(stack_t **head, unsigned int count);
void f_pop(stack_t **head, unsigned int count);
void f_swap(stack_t **head, unsigned int count);
void f_add(stack_t **head, unsigned int count);
void f_nop(stack_t **head, unsigned int count);
/*free.*/
void free_stack(stack_t *head);
/*execute.c*/
int execute(char *cont, stack_t **stack, unsigned int count, FILE *fd);
/*monty1.c*/
void addnode(stack_t **head, int n);
void f_push(stack_t **head, unsigned int count);
void f_pall(stack_t **head, unsigned int count);
void f_stack(stack_t **head, unsigned int count);
/*stack2.c*/
void f_mul(stack_t **head, unsigned int count);
void f_div(stack_t **head, unsigned int count);
void f_sub(stack_t **head, unsigned int count);
#endif
