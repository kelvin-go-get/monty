#include "monty.h"
var_t var = {0, NULL, NULL, NULL};
/**
 * main - checks the code
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success
 */

int main(int ac, char *av[])
{
	FILE *fd;
	ssize_t nchars = 1;
	unsigned int count = 0;
	stack_t *stack = NULL;
	size_t len = 0;
	char *cont;

	if (ac != 2)/* number of arguments is less than 2*/
	{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");/*open the file*/
	var.fd = fd;
	if (fd == NULL)/*file is null*/
	{
	fprintf(stderr, "Error: can't open file %s\n", av[1]);
	exit(EXIT_FAILURE);
	}
	while ((nchars = getline(&cont, &len, fd)) != -1)/*read input*/
	{
	var.cont = cont;
	count++;
	execute(cont, &stack, count, fd);/*func call*/
	}

	free_stack(stack);
	fclose(fd);

	if (cont)
	free(cont);
	return (0);
}
