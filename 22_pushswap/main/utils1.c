# include "push_swap.h"

t_dnode	*find_last_node(t_dnode *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	print_list_foward(t_dnode *head)
{
	ft_printf("Lista (crescente): ");
	while (head)
	{
		ft_printf("%d -> ", head->value);
		if (!head->next) break;
		head = head->next;
	}
	ft_printf("NULL\n");
}

void	print_cost(t_dnode *head)
{
	ft_printf("Lista: CUSTO: ");
	while (head)
	{
		ft_printf("%d -> ", head->push_cost);
		if (!head->next) break;
		head = head->next;
	}
	ft_printf("NULL\n");
}

void	print_target(t_dnode *head)
{
	ft_printf("Lista: ALVO: ");
	while (head)
	{
		ft_printf("%d -> ", head->target_node->value);
		if (!head->next) break;
		head = head->next;
	}
	ft_printf("NULL\n");
}

int	stack_len(t_dnode *stack)
{
	int	count;

	if (stack == NULL)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
