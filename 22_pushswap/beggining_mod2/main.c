//# include <stdlib.h>
# include "push_swap.h"

void	init_stack_a(t_dnode **a, char **argv)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			free_errors(a);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_errors(a);
		if (!is_unique(*a, (int)nbr))
			free_errors(a);
		//append_node(&a, (int)nbr);
		append_node(a, (int)nbr);
		i++;
	}
}

int	main (int argc, char **argv)
{
	t_dnode	*a;
	t_dnode	*b;
	//int		word_pos;
	bool	flag_splt;

	a = NULL;
	b = NULL;
	//word_pos = 1;
	flag_splt = false;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		//word_pos = 0;
		flag_splt = true;
	}

	init_stack_a(&a, argv+1);

	/*long	nbr;

	while (argv[word_pos])
	{
		if (is_number(argv[word_pos]) == false)
		{
			//free_split(argv, flag_splt, word_pos);// and error
			error_free(&a, argv, flag_splt);
			/////////////////
			ft_printf("Error\n");
			exit(1);
		}
		nbr = ft_atol(argv[word_pos]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			//free_split(argv, flag_splt, word_pos);// and error
			error_free(&a, argv, flag_splt);
			///////////////////////
			ft_printf("Error\n");
			exit(1);
		}
		if (is_unique(a, nbr) == false)
		{
			//////////////
			error_free(&a, argv, flag_splt);
			//free_split(argv, flag_splt, word_pos);// and error
			//free_list(a);
			ft_printf("Error\n");
			exit(1);
		}
		append_node(&a, nbr);
		//ft_printf("!%d!", word_pos);
		word_pos++;
	}*/
	if (flag_splt) //limpa argv após seu uso
		free_matrix(argv);

	do_stuff(a, b);

	// Encontrar o último nó para impressão reversa
	/*t_dnode *tail = a;
	while (tail->next)
		tail = tail->next;
	print_list_backward(tail);*/

	/*free_list(a);
	free_list(b);

	free_split(argv, flag_splt, word_pos);*/

	free_stack(&a);
	//free_stack(&a);
	free_stack(&b);

	print_both(a, b);

	return (0);
}
