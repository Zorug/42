# include "push_swap.h"

/*void	rev_rotate(t_dnode *head)
{
	//int	value0;
	int value1;
	int value2;

	//ft_printf("|%d|\n", head->value);
	value1 = head->value;
	head = head->next;
	while (head) // anda até o ultimo valor
	{
		value2 = head->value;
		head->value = value1;
		value1 = value2;
		if (!head->next) break;
		head = head->next;
	}
	while (head)
	{
		if (!head->prev) break;
		head = head->prev;
	}
	head->value = value1;
	//ft_printf("|%d|\n", head->value);
}*/

void	rev_rotate(t_dnode **stack)
{
	t_dnode	*last;
	int		len;
	len = stack_len(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return;
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}


void	rra(t_dnode **head_a)
//void	rra(t_dnode *head_a)
{
	rev_rotate(head_a);
	//rev_rotate(*head_a);
	ft_printf("rra\n");
}

//void	rrb(t_dnode *head_b)
void	rrb(t_dnode **head_b)
{
	rev_rotate(head_b);
	//rev_rotate(*head_b);
	ft_printf("rrb\n");
}

void	rrr(t_dnode **head_a, t_dnode **head_b)
//void	rrr(t_dnode *head_a, t_dnode *head_b)
{
	rev_rotate(head_a);
	rev_rotate(head_b);
	//rev_rotate(*head_a);
	//rev_rotate(*head_b);
	ft_printf("rrr\n");
}




/*void	rra(t_dnode **head_a)
//void	rra(t_dnode *head_a)
{
	//rev_rotate(head_a);
	rev_rotate(*head_a);
	ft_printf("rra\n");
}

//void	rrb(t_dnode *head_b)
void	rrb(t_dnode **head_b)
{
	//rev_rotate(head_b);
	rev_rotate(*head_b);
	ft_printf("rrb\n");
}

void	rrr(t_dnode **head_a, t_dnode **head_b)
//void	rrr(t_dnode *head_a, t_dnode *head_b)
{
	//rev_rotate(head_a);
	//rev_rotate(head_b);
	rev_rotate(*head_a);
	rev_rotate(*head_b);
	ft_printf("rrr\n");
}
*/