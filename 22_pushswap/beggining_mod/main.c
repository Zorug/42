//# include <stdlib.h>
# include "push_swap.h"

int	main (int argc, char **argv)
{
	t_dnode	*head_a;
	t_dnode	*head_b;
	int		word_pos;
	bool	flag_splt;

	head_a = NULL;
	head_b = NULL;
	word_pos = 1;
	flag_splt = false;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
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
		append_node(&head_a, nbr);
		//ft_printf("!%d!", word_pos);
		word_pos++;
	}
	if (flag_splt) //limpa argv após seu uso
		free_matrix(argv);

	do_stuff(head_a, head_b);

	// Encontrar o último nó para impressão reversa
	/*t_dnode *tail = head_a;
	while (tail->next)
		tail = tail->next;
	print_list_backward(tail);*/

	/*free_list(head_a);
	free_list(head_b);

	free_split(argv, flag_splt, word_pos);*/

	free_stack(&head_a);
	//free_stack(&head_a);
	//free_stack(&head_b);

	print_both(head_a, head_b);

	return (0);
}
