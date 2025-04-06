# include "push_swap.h"

void 	pa(t_dnode **head_a, t_dnode **head_b)
{
	t_dnode *tmp;

	if(!(*head_b))
		return ;
	tmp = *head_b;
	*head_b = (*head_b)->next;
	tmp->next = NULL;
	ft_stackadd_front(head_a, tmp);
	ft_printf("pa\n");
}

void	pb(t_dnode **head_a, t_dnode **head_b)
{
	t_dnode	*tmp;

	if (!(*head_a))
		return ;
	tmp = *head_a;
	*head_a = (*head_a)->next;
	tmp->next = NULL;
	ft_stackadd_front(head_b, tmp);
	ft_printf("pb\n");
}
