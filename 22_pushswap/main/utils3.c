#include "push_swap.h"

int	argv_cnt(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		i++;
	}
	return (i);
}

static void	check_and_add(char **argv, t_dnode **a,
	int i, bool argv_free)
{
	long	nbr;

	if (!is_number(argv[i]))
		error_free(a, argv, argv_free);
	nbr = ft_atol(argv[i]);
	if (nbr > INT_MAX || nbr < INT_MIN)
		error_free(a, argv, argv_free);
	if (!is_unique(*a, nbr))
		error_free(a, argv, argv_free);
	ft_stackadd_back(a, ft_stack_new(nbr));
}

t_dnode	*get_stack(int argc, char **argv)
{
	t_dnode	*a;
	int		i;
	bool	argv_free;

	argv_free = false;
	a = NULL;
	i = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = argv_cnt(argv);
		i = 0;
		argv_free = true;
	}
	while (i < argc)
		check_and_add(argv, &a, i++, argv_free);
	if (argv_free)
		free_matrix(argv);
	return (a);
}

void	ft_sort(t_dnode **a, t_dnode **b)
{
	do_stuff(a, b);
	ft_stackclear(b, ft_free);
}
