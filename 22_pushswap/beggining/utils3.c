# include "push_swap.h"

/*void	swap_a(t_dnode *head)
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

/*void	rotate_a(t_dnode *head)
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
}*/

/*void	rev_rotate_a(t_dnode *head)
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

/*void push_b(t_dnode **head_a, t_dnode **head_b)
{
	t_dnode *temp = *head_a;  // Primeiro nó da pilha A

	if (!*head_a) return ;  // Se a pilha A estiver vazia, não faz nada.

	// Remove o primeiro nó de A
	*head_a = (*head_a)->next;
	if (*head_a)
		(*head_a)->prev = NULL;

	// Adiciona o nó removido no topo da pilha B
	temp->next = *head_b;
	if (*head_b)
		(*head_b)->prev = temp;
	*head_b = temp;
	(*head_b)->prev = NULL;
}*/