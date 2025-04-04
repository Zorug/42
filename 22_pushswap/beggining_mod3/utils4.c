# include "push_swap.h"

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
}

//static void	move_a_to_b(t_dnode **a, t_dnode **b)
void	move_a_to_b(t_dnode **a, t_dnode **b)
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

//static void	move_b_to_a(t_dnode **a, t_dnode **b)
void	move_b_to_a(t_dnode **a, t_dnode **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

//static void	min_on_top(t_dnode **a)
void	min_on_top(t_dnode **a)
{
	while ((*a)->value != find_min(*a)->value)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}