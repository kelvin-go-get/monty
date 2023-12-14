#include "monty.h"

/**
 * f_mul -   multiplies the 2nd top elem swith top elems of the stack
 * @head: head
 * @count: line_number
 *
 * Return: nothing
 */
void f_mul(stack_t **head, unsigned int count)
{
	stack_t *temp1, *temp2;

	if (*head == NULL || (*head)->next)/*if head and head next null print top*/
	{
	fprintf(stderr, "L%u: can't mul, stack too short\n", count);
	fclose(var.fd);
	free(var.cont);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
	temp1 = *head;
	temp2 = temp1->next;

	temp2->n = temp2->n * temp1->n;/*multiply*/
	if (temp1->next)
	temp1->next = temp1->next->next;
	else
	*head = NULL;
	free(temp1);
}

/**
 * f_div - divides the top two elemts of the stack
 * @head: head
 * @count: line_number
 *
 * Return: nothing
 */

void f_div(stack_t **head, unsigned int count)
{
	stack_t *temp1, *temp2;

	if (*head == NULL || (*head)->next == NULL)/*stack has < 2 elements*/
	{
	fprintf(stderr, "L%u: can't div, stack too short\n", count);
	fclose(var.fd);
	free(var.cont);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
	else/*div the two elemts*/
	{
	temp1 = *head;
	temp2 = temp1->next;

	if (temp1->n == 0)
	{
	fprintf(stderr, "L%u: division by zero\n", count);
	/*top element of stack is 0*/
	fclose(var.fd);
	free(var.cont);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
	temp2->n = temp2->n / temp1->n;
	if (temp1->next)
	temp2->next = temp1->next->next;
	else
	*head = NULL;
	free(temp1);
	}
}
/**
 * f_sub - subtracts the top two elements of the stack.
 * @head: head
 * @count: line_number
 *
 * Return: nothing
 */
void f_sub(stack_t **head, unsigned int count)
{
	int sub;
	stack_t *temp1, *temp2;

	if (count < 2)/*check if the stack has least 2 elements*/
	{/*print to stderr an exit*/
	fprintf(stderr, "L%u : can't sub, stack too short\n", count);
	fclose(var.fd);
	free(var.cont);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
	else/*retrive the top 2 elements*/
	{
	temp1 = *head;
	temp2 = temp1->next;

	sub = temp2->n - temp1->n;/* sub the values of the top two elements*/

	if (temp1->next)
	temp1->next = temp1->next->next;
	else
	*head = NULL;
	temp1->n = sub;
	free(temp2);/*free memory*/
	}
}
