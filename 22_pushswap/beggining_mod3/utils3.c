# include "push_swap.h"

void	ft_stackadd_front(t_dnode **stack, t_dnode *new)
{
	if (!new || !stack)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	*stack = new;
}

t_dnode	*ft_stack_new(long content)
{
	t_dnode	*new;

	new = (t_dnode *)malloc(sizeof(t_dnode));
	if (!new)
		return (NULL);
	new->value = content;
	new->next = NULL;
	return (new);
}

t_dnode	*ft_stack_last(t_dnode *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_stackadd_back(t_dnode **stack, t_dnode *new)
{
	t_dnode	*last;

	if (!new || !stack)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = ft_stack_last(*stack);
	last->next = new;
}

int	argv_cnt(char **argv)
{
	int i;

	i = 0;
	while(argv[i])
	{
		i++;
		//*argv++;
	}
	ft_printf("\n!!%d!!\n", i);
	return (i);
}

t_dnode	*get_stack(int argc, char **argv)
{
	int		i;
	t_dnode *a;
	long	nbr;
	bool	argv_free = false;

	i = 1;
	a = NULL;
	if (argc == 2)
		{
			argv = ft_split(argv[1], ' ');
			//contar o número de argv e atribuir a argv
			argc = argv_cnt(argv);
			i = 0;
			//argc++;
			argv_free = true;
		}
	while (i < argc)
	{
		if (!is_number(argv[i]))
			error_free(&a, argv, argv_free);
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(&a, argv, argv_free);
		if (!is_unique(a, nbr))
			error_free(&a, argv, argv_free);
		ft_stackadd_back(&a, ft_stack_new(nbr));
		i++;
	}
	if (argv_free == true)
		free_matrix(argv);
	return (a);
}

//void	ft_sort(t_dnode **a)
void	ft_sort(t_dnode **a, t_dnode **b)
{
	//t_dnode *b;

	//b = NULL;

	//do_stuff(a, &b);
	do_stuff(a, b);

	//ft_stackclear(&b, ft_free);
	ft_stackclear(b, ft_free);
}