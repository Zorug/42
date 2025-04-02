#include "push_swap.h"

// FREE FUNCTIONS

void	ft_free(void *x)
{
	if (!x)
		return ;
	free (x);
}

void	ft_stackclear(t_dnode **stack, void (*del)(void*))
{
	t_dnode	*aux;

	if (!*stack || !del)
		return ;
	while (*stack)
	{
		aux = (*stack)->next;
		ft_free(*stack);
		*stack = aux;
	}
}

void	free_matrix(char **argv)
{
	int	i;

	if (argv == NULL || *argv == NULL)
		return ;
	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

void	free_stack(t_dnode **stack)
{
	t_dnode	*tmp;
	t_dnode	*current;

	//ft_printf(" !FREE0! ");
	if (stack == NULL)// || *stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		//ft_printf(" !FREE1! ");
		tmp = current->next;
		//////
		current->value = 0;
		//////
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	error_free(t_dnode **a, char **argv, bool flag_argc_2)
{
	free_stack(a);
	if (flag_argc_2)
		free_matrix(argv);
	//write(2, "Error\n", 6);
    ft_printf("Error\n");
	exit(1);
}