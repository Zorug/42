# include "push_swap.h"

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
}

void	rra(t_dnode **head_a)
{
	rev_rotate(head_a);
	ft_printf("rra\n");
}

void	rrb(t_dnode **head_b)
{
	rev_rotate(head_b);
	ft_printf("rrb\n");
}

void	rrr(t_dnode **head_a, t_dnode **head_b)
{
	rev_rotate(head_a);
	rev_rotate(head_b);
	ft_printf("rrr\n");
}
