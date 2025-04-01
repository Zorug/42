# include "push_swap.h"

t_dnode	*find_last_node(t_dnode *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	append_node(t_dnode **stack, int nbr)
{
	t_dnode	*node;
	t_dnode	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_dnode));
	if (node == NULL)
		return ;
	ft_printf(" !MALLOCANUM! ");
	node->next = NULL;
	node->value = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

// Função para imprimir a lista
void	print_list_foward(t_dnode *head)
{
	ft_printf("Lista (crescente): ");
	while (head)
	{
		ft_printf("%d -> ", head->value);
		if (!head->next) break; // Guarda o último nó para a impressão reversa
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