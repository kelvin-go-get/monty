#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @count: line_number
 * Return: no return
*/
void f_push(stack_t **head, unsigned int count)
{
	int n, j = 0, flag = 0;

	if (!var.arg)/*arg variable is NULL*/
	{/*print error and exit prog*/
	fprintf(stderr, "L%d: usage: push integer\n", count);
	fclose(var.fd);
	free(var.cont);
	exit(EXIT_FAILURE);
	}
	else if (var.arg[0] == '-')/*if first arg is negative*/
	j++;/*check next string*/

	else
	{
	for (; var.arg[j] != '\0'; j++)
	{
	if (var.arg[j] > 57 || var.arg[j] < 48)
	flag = 1;/*char is not a digit*/
	}
	if (flag == 1)/* print to stderr*/
	{
	fprintf(stderr, "L%d: usage: push integer\n", count);
	fclose(var.fd);
	free(var.cont);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
	}
	n = atoi(var.arg);/*converts arg string into an integer*/
	if (var.lifi == 0)
	addnode(head, n);/*add anew node*/
	/*else
	addqueue(head, n);*/
}
/**
 * f_pall - prints the stack
 * @head: stack head
 * @count: no used
 * Return: no return
*/
void f_pall(stack_t **head, unsigned int count)
{
	stack_t *temp;
	(void)count;

	temp = *head;/*assigningtemp to head*/
	if (temp == NULL)/*stack is empty*/
	return;
	while (temp)/*iterate through each nodein the stack*/
	{
	printf("%d\n", temp->n);/*print*/
	temp = temp->next;
	}
}
#include "monty.h"
/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void addnode(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));/*allocate memory to the new node*/

	if (new_node == NULL)/*node is empty*/
	{
	printf("Error\n");/*error*/
	exit(0);
	}
	new_node->n = n;/*updating head of stack to pint to new_node*/
	new_node->next = *head;
	new_node->prev = NULL;

	if (*head != NULL)/*check is stack is empty before adding a new node*/
	(*head)->prev = new_node;
	*head = new_node;
}
