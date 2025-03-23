# include "push_swap.h"

void    free_split(char **argv, bool flag_splt, int word_pos)
{
    if (flag_splt == true)
	{
		while (--word_pos >= 0)
			free(argv[word_pos]);
		free(argv);
	}
}

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

bool	is_unique(t_dnode *head_a, int nbr)
{
	if (NULL == head_a)
		return (true);
	while (head_a)
	{
		if (head_a->value == nbr)
			return (false);
		head_a = head_a->next;
	}
	return (true);
}

void	print_both(t_dnode *head_a, t_dnode *head_b)
{
	ft_printf("A:\n");
	print_list_foward(head_a);
	ft_printf("B:\n");
	print_list_foward(head_b);
	ft_printf("\n");
}

void	do_stuff(t_dnode *head_a, t_dnode *head_b)
{
	print_both(head_a, head_b);
	pb(&head_a, &head_b);
	pb(&head_a, &head_b);
	pb(&head_a, &head_b);
	pb(&head_a, &head_b);
	print_both(head_a, head_b);

	sa(&head_a);
	sb(&head_b);
	print_both(head_a, head_b);
	ss(&head_a, &head_b);
	print_both(head_a, head_b);

	ra(&head_a);
	rb(&head_b);
	print_both(head_a, head_b);
	rr(&head_a, &head_b);
	print_both(head_a, head_b);

	rra(&head_a);
	rrb(&head_b);
	print_both(head_a, head_b);
	rrr(&head_a, &head_b);
	print_both(head_a, head_b);
}