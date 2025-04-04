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

/*
//static void	rotate_both(t_dnode **a, t_dnode **b,
void	rotate_both(t_dnode **a, t_dnode **b,
							t_dnode *cheapest_node)
{
	while (*b != cheapest_node->target_node
				&& *a != cheapest_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

//static void	rev_rotate_both(t_dnode **a, t_dnode **b,
void	rev_rotate_both(t_dnode **a, t_dnode **b,
	t_dnode *cheapest_node)
{
	while (*b != cheapest_node->target_node
				&& *a != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}*/

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

//void	do_stuff(t_dnode **a)
void	do_stuff(t_dnode **a, t_dnode **b)
{
	int	len_a;

	len_a = stack_len(*a);

	//1. push 2

	if (len_a-- > 3)
		pb(a, b);
	if (len_a-- > 3)
		pb(a, b);

	print_both(*a, *b, print_list_foward);

	while (len_a-- > 3)
 	{
		init_nodes_a(*a, *b);


		ft_printf("\n");	


		move_a_to_b(a, b);

		print_both(*a, *b, print_list_foward);

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

}
