#include "monty.h"
/**
* execute - executes the opcode
* @stack: statck
* @count: line_counter
* @fd: poiner to monty file
* @cont: line content
* Return: nothing
*/
int execute(char *cont, stack_t **stack, unsigned int count, FILE *fd)
{
	instruction_t opst[] = {
				{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
				{"pop", f_pop},
				{"swap", f_swap},
				{"add", f_add},
				{"nop", f_nop},
				/*{"sub", f_sub},
				{"div", f_div},
				{"mul", f_mul},
				{"mod", f_mod},
				{"pchar", f_pchar},
				{"pstr", f_pstr},
				{"rotl", f_rotl},
				{"rotr", f_rotr},
				{"queue", f_queue},
				{"stack", f_stack},*/
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(cont, " \n\t");
	if (op && op[0] == '#')
		return (0);
	var.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(fd);
		free(cont);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
