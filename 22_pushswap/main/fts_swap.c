# include "push_swap.h"

void	swap(t_dnode **head)
{
	t_dnode	*tmp;

	if (!(*head) || !(*head)->next)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
}

void	sa(t_dnode **head_a)
{
	swap(head_a);
	ft_printf("sa\n");
}

void	sb(t_dnode **head_b)
{
	swap(head_b);
	ft_printf("sb\n");
}

void	ss(t_dnode **head_a, t_dnode **head_b)
{
	swap(head_a);
	swap(head_b);
	ft_printf("ss\n");
}
