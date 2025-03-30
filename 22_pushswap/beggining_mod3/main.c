//# include <stdlib.h>
# include "push_swap.h"

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

int	main (int argc, char **argv)
{
	t_dnode	*head_a;
	//t_dnode	*head_b;
	//int		word_pos;
	//bool	flag_splt;

	head_a = NULL;
	//head_b = NULL;
	//word_pos = 1;
	//flag_splt = false;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);

	head_a = get_stack(argc, argv);

	/*
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		word_pos = 0;
		flag_splt = true;
	}

	long	nbr;

	while (argv[word_pos])
	{
		if (is_number(argv[word_pos]) == false)
		{
			//free_split(argv, flag_splt, word_pos);// and error
			error_free(&head_a, argv, flag_splt);
			/////////////////
			ft_printf("Error\n");
			exit(1);
		}
		nbr = ft_atol(argv[word_pos]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			//free_split(argv, flag_splt, word_pos);// and error
			error_free(&head_a, argv, flag_splt);
			///////////////////////
			ft_printf("Error\n");
			exit(1);
		}
		if (is_unique(head_a, nbr) == false)
		{
			//////////////
			error_free(&head_a, argv, flag_splt);
			//free_split(argv, flag_splt, word_pos);// and error
			//free_list(head_a);
			ft_printf("Error\n");
			exit(1);
		}
		//append_node(&head_a, nbr);
		ft_stackadd_back(&head_a, ft_stack_new(nbr));
		//ft_printf("!%d!", word_pos);
		word_pos++;
	}*/

	//if (flag_splt) //limpa argv após seu uso
	//	free_matrix(argv);

	//do_stuff(head_a, head_b);

	ft_sort(&head_a);
	//ft_sort(head_a);

	//do_stuff(head_a);

	ft_stackclear(&head_a, ft_free);
	//ft_stackclear(&head_b, ft_free);

	//print_both(head_a, head_b);

	return (0);
}
