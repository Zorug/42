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

void	print_both(t_dnode *a, t_dnode *b, void (*func)(t_dnode *))
{
	ft_printf("A: ");
	func(a);
	ft_printf("B: ");
	func(b);
	ft_printf("\n");
}

/*void	print_both(t_dnode *head_a, t_dnode *head_b)
{
	ft_printf("A: ");
	print_list_foward(head_a);
	ft_printf("B: ");
	print_list_foward(head_b);
	ft_printf("\n");
}

void	print_both_cost(t_dnode *head_a, t_dnode *head_b)
{
	ft_printf("A: ");
	print_cost(head_a);
	ft_printf("B: ");
	print_cost(head_b);
	ft_printf("\n");
}*/

/*void	print_test(t_dnode *head_a, t_dnode *head_b, void (*ft))
{
	ft_printf("A: ");
	print_cost(head_a);
	ft_printf("B: ");
	print_cost(head_b);
	ft_printf("\n");
}*/

/*void	push_cost(t_dnode **a, t_dnode **b)
{
	int		i;
	int 	a_len;
	//int 	b_len;
	//t_dnode	*temp;
	
	i = 0;
	//temp = *a;
	a_len = stack_len(*a);
	//temp = *b;
	//b_len = stack_len(*b);
	ft_printf("||- %d -||", a_len);
	while(*a)
	{
		(*a)->cost = i;
		ft_printf("<<%d|%d|%d>>",(*a)->cost,(*b)->cost, i);
		(*a) = (*a)->next;
		i++;
		//rotates to top ou rr, count
	}
}*/

void	do_stuff(t_dnode **a)
{
	t_dnode	*b;
	//t_dnode *tmp;

	b = NULL;

	//1. push 2
	pb(a, &b);
	pb(a, &b);
	//tmp = *a;
	//print_both(*a, b);
	print_both(*a, b, print_list_foward);

	//calculate pushcost
	//push_cost(&a, &b);
	init_nodes(*a, b);


	//print_both(*a, b, print_cost);
	print_cost(*a);

	ft_printf("\n");	
	//print_both(*a, b, print_target);
	print_target(*a);

	/*rra(a);
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
	print_both(tmp, b);*/

	ft_stackclear(&b, ft_free);
}
