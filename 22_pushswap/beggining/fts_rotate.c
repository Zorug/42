# include "push_swap.h"

void	rotate(t_dnode *head)
{
	int	value1;
	int	value2;

	value1 = head->value;
	while (head) // anda até o ultimo valor
	{
		if (!head->next) break;
		head = head->next;
	}
	//ft_printf("|%d|\n", head->value);
	while (head) // anda até o ultimo valor
	{
		value2 = head->value;
		head->value = value1;
		value1 = value2;
		if (!head->prev) break;
		head = head->prev;
	}
	//ft_printf("|%d|\n", head->value);
}

//void	ra(t_dnode *head_a)
void	ra(t_dnode **head_a)
{
	//rotate(head_a);
	rotate(*head_a);
	ft_printf("ra\n");
}

//void	rb(t_dnode *head_b)
void	rb(t_dnode **head_b)
{
	//rotate(head_b);
	rotate(*head_b);
	ft_printf("rb\n");
}

//void	rr(t_dnode *head_a, t_dnode *head_b)
void	rr(t_dnode **head_a, t_dnode **head_b)
{
//	rotate(head_a);
//	rotate(head_b);
	rotate(*head_a);
	rotate(*head_b);
	ft_printf("rr\n");
}