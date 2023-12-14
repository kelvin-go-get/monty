#include "monty.h"

/**
 * f_pint -  prints top
 * @head: head
 * @count: line_number
 *
 * Return: nothing
 */
void f_pint(stack_t **head, unsigned int count)
{
	if (*head != NULL)/*if head is not null print top*/
	{
	printf("%d\n", (*head)->n);
	}
	else/*head is null*/
	{
	fprintf(stderr, "L%u: can't pint, stack empty\n", count);
	fclose(var.fd);
	free(var.cont);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
}
/**
 * f_pop - removes the top element of the stack
 * @head: head
 * @count: line_number
 *
 * Return: nothing
 */
void f_pop(stack_t **head, unsigned int count)
{
	stack_t  *temp;

	if (*head == NULL)/*head is null*/
	{
	/* handle error;closefile, free memory and exit*/
	fprintf(stderr, "L%u: can't pop an empty stack\n", count);
	fclose(var.fd);
	free(var.cont);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
	else/*pop opcode*/
	{
	temp = *head;
	*head = (*head)->next;
	free(temp);
	count--;/*remove the top element*/
	}
}
/**
 * f_swap - swaps the top two elemts of the stack
 * @head: head
 * @count: line_number
 *
 * Return: nothing
 */

void f_swap(stack_t **head, unsigned int count)
{
	stack_t *temp1, *temp2;

	if (*head == NULL || (*head)->next == NULL)/*stack has < 2 elements*/
	{
	fprintf(stderr, "L%u: can't swap, stack too short\n", count);
	fclose(var.fd);
	free(var.cont);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
	else/*swap the two elemts*/
	{
	temp1 = *head;
	temp2 = (*head)->next;
	*head = temp2;
	temp1->next = temp2->next;
	temp2->next = temp1;
	*head = temp2;
	}
}
/**
 * f_add - adds the top two elements of the stack.
 * @head: head
 * @count: line_number
 *
 * Return: nothing
 */
void f_add(stack_t **head, unsigned int count)
{
	stack_t *temp1, *temp2;

	if (count < 2)
	{
	fprintf(stderr, "L%u : can't add, stack too short\n", count);
	fclose(var.fd);
	free(var.cont);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
	else
	{
	temp1 = *head;
	temp2 = temp1->next;
	temp2->n += temp1->n;
	free(temp1);
	*head = temp2;
	}
}
/**
 * f_nop - doesn't do anything
 * @head: head
 * @count: line_number
 *
 * Return: nothing
 */
void f_nop(stack_t **head, unsigned int count)
{
	(void) head;
	(void) count;
}
