//# include <stdlib.h>
# include "push_swap.h"

int	main (int argc, char **argv)
{
	t_dnode	*head_a;
	//t_dnode	*head_b;
	int		word_pos;
	bool	flag_splt;

	head_a = NULL;
	//head_b = NULL;
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

	//verify values
		//verify the values, if everithing ok, then append
	if (error_repeat(argv, flag_splt) == true);
	{
		free_split(argv, flag_splt, word_pos);// and error
		ft_printf("Error\n");
		exit(1);
	}
		// if (error_limits(argv, flag_splt) == true);
		//	free_split and error
		// if (error_syntax(argv, flag_splt) == true);
		//	free_split and error

	while (argv[word_pos])//append the values
	{
		append_node(&head_a, ft_atol(argv[word_pos]));
		word_pos++;
	}

	print_list_foward(head_a);

	// Encontrar o último nó para impressão reversa
	t_dnode *tail = head_a;
	while (tail->next)
		tail = tail->next;
	print_list_backward(tail);

	free_list(head_a);

	free_split(argv, flag_splt, word_pos);

/*	if (flag_splt == true)
	{
		while (--word_pos >= 0)
			free(argv[word_pos]);
		free(argv);
	}*/

	return (0);
}
