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

void	do_stuff(t_dnode **a)
{
	t_dnode	*b;
	t_dnode *tmp;

	b = NULL;
	tmp = *a;
	print_both(tmp, b);
	pb(a, &b);
	tmp = *a;
	print_both(tmp, b);
	pb(a, &b);
	tmp = *a;
	print_both(tmp, b);
	pb(a, &b);
	tmp = *a;
	print_both(tmp, b);

	rra(a);
	tmp = *a;
	print_both(tmp, b);

	rrb(&b);
	tmp = *a;
	print_both(tmp, b);

	rrr(a, &b);
	tmp = *a;
	print_both(tmp, b);

	ra(a);
	tmp = *a;
	print_both(tmp, b);

	rb(&b);
	tmp = *a;
	print_both(tmp, b);

	rr(a, &b);
	tmp = *a;
	print_both(tmp, b);

	sa(a);
	tmp = *a;
	print_both(tmp, b);

	sb(&b);
	tmp = *a;
	print_both(tmp, b);

	ss(a, &b);
	tmp = *a;
	print_both(tmp, b);

	ft_stackclear(&b, ft_free);
}
