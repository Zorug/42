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

/*void	rev_rotate(t_dnode **stack)
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
}*/


/*void	rra(t_dnode **head_a)
//void	rra(t_dnode *head_a)
{
	rev_rotate(head_a);
	//rev_rotate(*head_a);
	ft_printf("rra\n");
}*/

//void	rrb(t_dnode *head_b)
/*void	rrb(t_dnode **head_b)
{
	rev_rotate(head_b);
	//rev_rotate(*head_b);
	ft_printf("rrb\n");
}*/

/*void	rrr(t_dnode **head_a, t_dnode **head_b)
//void	rrr(t_dnode *head_a, t_dnode *head_b)
{
	rev_rotate(head_a);
	rev_rotate(head_b);
	//rev_rotate(*head_a);
	//rev_rotate(*head_b);
	ft_printf("rrr\n");
}*/




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

void	rev_rotate(t_dnode **head)
{
	t_dnode	*tmp;
	t_dnode *penult;

	if (!(*head) || !(*head)->next)
		return ;
	tmp = *head;
	*head = ft_stack_last(*head);
	(*head)->next = tmp;
	while (tmp != *head)
	{
		penult = tmp;
		tmp = tmp->next;
	}
	penult->next = NULL;
	//if (!print_ft)
	//	ft_printf("rra\n");
}

void	rra(t_dnode **head_a)
{
	rev_rotate(head_a);
	ft_printf("rra\n");
}

/*void	rra(t_dnode **head_a, bool print_ft)
{
	t_dnode	*tmp;
	t_dnode *penult;

	if (!(*head_a) || !(*head_a)->next)
		return ;
	tmp = *head_a;
	*head_a = ft_stack_last(*head_a);
	(*head_a)->next = tmp;
	while (tmp != *head_a)
	{
		penult = tmp;
		tmp = tmp->next;
	}
	penult->next = NULL;
	if (!print_ft)
		ft_printf("rra\n");
}*/

void	rrb(t_dnode **head_b)
{
	rev_rotate(head_b);
	ft_printf("rrb\n");
}

/*void	rrb(t_dnode **head_b, bool print_ft)
{
	t_dnode	*tmp;
	t_dnode	*penult;

	if (!(*head_b) || !(*head_b)->next)
		return ;
	tmp = *head_b;
	*head_b = ft_stack_last(*head_b);
	(*head_b)->next = tmp;
	while (tmp != *head_b)
	{
		penult = tmp;
		tmp = tmp->next;
	}
	penult->next = NULL;
	if (!print_ft)
		ft_printf("rrb\n");
}*/

/*void	rrr(t_dnode **head_a, t_dnode **head_b, bool print_ft)
//void	rrr(t_dnode *head_a, t_dnode *head_b)
{
	rra(head_a, print_ft);
	rrb(head_b, print_ft);
	//rev_rotate(*head_a);
	//rev_rotate(*head_b);
	if (print_ft)
		ft_printf("rrr\n");
}*/

void	rrr(t_dnode **head_a, t_dnode **head_b)
{
	rev_rotate(head_a);
	rev_rotate(head_b);
	ft_printf("rrr\n");
}