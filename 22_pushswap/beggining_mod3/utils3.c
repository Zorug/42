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
	//new->nbr = content;
	new->value = content;
	new->next = NULL;
	return (new);
}

t_dnode	*ft_stack_last(t_dnode *stack)
{
	if (!stack)
		return (0);
//		return (NULL);
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

t_dnode	*get_stack(int argc, char **argv)
{
	int		i;
	t_dnode *a;
	int		j;
	bool	argv_free = false;

	i = 1;
	a = NULL;
	if (argc == 2)
		//exit (EXIT_SUCCESS);
		{
			argv = ft_split(argv[1], ' ');
			//word_pos = 0;
			//flag_splt = true;
			i = 0;
			argc++;
			argv_free = true;
		}
	while (i < argc)
	{
		j = ft_atoi(argv[i]);
		ft_stackadd_back(&a, ft_stack_new(j));
		i++;
	}
	//free argv!!
	//ft_stackclear(argv, ft_free);
	//ft_free(argv);
	if (argv_free == true) free_matrix(argv);
	return (a);
}

/*t_dnode	*get_stack(int argc, char **argv)
{
	int	i;
	t_dnode *a;
	int	j;

	i = 1;
	a = NULL;
	if (argc == 2)
		exit (EXIT_SUCCESS);
	while (i < argc)
	{
		j = ft_atoi(argv[i]);
		ft_stackadd_back(&a, ft_stack_new(j));
		i++;
	}
	return (a);
}*/

void	ft_sort(t_dnode **a)
//void	ft_sort(t_dnode *a)
{
//	t_dnode	*b;

//	b = NULL;

	do_stuff(a);

	//ft_stackclear(&b, ft_free);
}