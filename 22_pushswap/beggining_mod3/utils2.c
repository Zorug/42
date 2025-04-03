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

/*t_dnode	*find_max(t_dnode *stack)
{
	long	max;
	t_dnode	*max_node;

	if (!stack)
		return NULL;
	max = LONG_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}*/

void	sort_three(t_dnode **a)
{
	t_dnode	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

static void	move_b_to_a(t_dnode **a, t_dnode **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

static void	min_on_top(t_dnode **a)
{
	while ((*a)->value != find_min(*a)->value)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

//void	do_stuff(t_dnode **a)
void	do_stuff(t_dnode **a, t_dnode **b)
{
	int	len_a;

	len_a = stack_len(*a);

	//t_dnode	*b;

	//b = NULL;

	//1. push 2
	//pb(a, &b);
	//pb(a, &b);
	if (len_a-- > 3)
		pb(a, b);
	if (len_a-- > 3)
		pb(a, b);
	//print_both(*a, b);
//	print_both(*a, b, print_list_foward);
	print_both(*a, *b, print_list_foward);

	//calculate pushcost
	//push_cost(&a, &b);
	//init_nodes(*a, b);

	while (len_a-- > 3)
 	{
		init_nodes_a(*a, *b);

		//print_both(*a, b, print_cost);
		//print_cost(*a);

		ft_printf("\n");	
		//print_both(*a, b, print_target);
		//print_target(*a);

		move_a_to_b(a, b);
		//print_both(*a, b, print_list_foward);
		print_both(*a, *b, print_list_foward);
		//ft_printf("<%d>", len_a);
	}
	sort_three(a);
	print_both(*a, *b, print_list_foward);

	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	print_both(*a, *b, print_list_foward);
	current_index(*a);
	print_both(*a, *b, print_list_foward);
	min_on_top(a);
	print_both(*a, *b, print_list_foward);
	/*rra(a);
	rrb(&b);
	rrr(a, &b);
	ra(a);
	rb(&b);
	rr(a, &b);
	sa(a);
	sb(&b);
	ss(a, &b);*/
	//ft_stackclear(&b, ft_free);
}
