# include "push_swap.h"

/*void	swap(t_dnode *head)
{
	int	value1;
	int	value2;

	value1 = head->value;

	head = head->next;
	value2 = head->value;
	head->value = value1;

	head = head->prev;
	head->value = value2;
}*/

void	swap(t_dnode **head)
{
	int	len;

	len = stack_len(*head);
	if (*head == NULL || head == NULL || len == 1)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

//void	sa(t_dnode *head_a)
void	sa(t_dnode **head_a)
{
	swap(head_a);
	//swap(*head_a);
	ft_printf("sa\n");
}

void	sb(t_dnode **head_b)
//void	sb(t_dnode *head_b)
{
	swap(head_b);
	//swap(*head_b);
	ft_printf("sb\n");
}

//void	ss(t_dnode *head_a, t_dnode *head_b)
void	ss(t_dnode **head_a, t_dnode **head_b)
{
	swap(head_a);
	swap(head_b);
	//swap(*head_a);
	//swap(*head_b);
	ft_printf("ss\n");
}
