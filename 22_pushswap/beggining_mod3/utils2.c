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

t_dnode	*get_cheapest(t_dnode *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

static void	rotate_both(t_dnode **a, t_dnode **b,
							t_dnode *cheapest_node)
{
	while (*b != cheapest_node->target_node
				&& *a != cheapest_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_dnode **a, t_dnode **b,
	t_dnode *cheapest_node)
{
	while (*b != cheapest_node->target_node
				&& *a != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

void	prep_for_push(t_dnode **stack, t_dnode *top_node,
						char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
			{
				//ft_printf("!TESTE!\n");
				rb(stack);
			}
			else
				rrb(stack);
		}
	}
}

static void	move_a_to_b(t_dnode **a, t_dnode **b)
{
	t_dnode	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(a, b);
}

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


	move_a_to_b(a, &b);
	print_both(*a, b, print_list_foward);
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
