//# include <stdlib.h>
# include "push_swap.h"

int	main (int argc, char **argv)
{
	t_dnode	*head_a;

	head_a = NULL;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		ft_printf("Error\n");
		return (1);
	}

	head_a = get_stack(argc, argv);


	//do_stuff(head_a, head_b);

	ft_sort(&head_a);
	//ft_sort(head_a);

	//do_stuff(head_a);

	ft_stackclear(&head_a, ft_free);

	//print_both(head_a, head_b);

	return (0);
}
