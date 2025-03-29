# include "push_swap.h"

bool is_number(char *str)
{
	if (!(*str == '+'
		|| *str == '-'
		|| (*str >= '0' && *str <= '9')))
				return (false);
	if ((*str == '+'
			|| *str == '-')
			&& !(str[1] >= '0' && str[1] <= '9'))
				return (false);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (false);
	}
	return (true);
}

bool	is_unique(t_dnode *a, int nbr)
{
	if (a == NULL)
		return (true);
	while (a)
	{
		if (a->value == nbr)
			return (false);
		a = a->next;
	}
	return (true);
}

void	free_stack(t_dnode **stack)
{
	t_dnode	*tmp;
	t_dnode	*current;

	ft_printf(" !FREE0! ");
	if (stack == NULL)// || *stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		ft_printf(" !FREE1! ");
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
	write(2, "Error\n", 6);
	exit(1);
}

void	free_errors(t_dnode **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}