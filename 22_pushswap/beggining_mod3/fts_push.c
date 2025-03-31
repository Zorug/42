# include "push_swap.h"

/*void	push(t_dnode **head_src, t_dnode **head_dst)
{
	t_dnode *temp = *head_src;  // Primeiro nó da pilha A

	if (!*head_src) 
	{
		//free_list(temp);
		return ;  // Se a pilha A estiver vazia, não faz nada.
	}
	// Remove o primeiro nó de A
	*head_src = (*head_src)->next;
	if (*head_src)
		(*head_src)->prev = NULL;

	// Adiciona o nó removido no topo da pilha B
	temp->next = *head_dst;
	if (*head_dst)
		(*head_dst)->prev = temp;
	*head_dst = temp;
	(*head_dst)->prev = NULL;
	//free_list(temp);
}*/

/*void	push(t_dnode **src, t_dnode **dest)
{
	t_dnode	*node_to_push;

	if (*src == NULL)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (*dest == NULL)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
}*/

/*void	pa(t_dnode **head_a, t_dnode **head_b)
//void	pa(t_dnode *head_a, t_dnode *head_b)
{
	push(head_b, head_a);
//	push(&head_b, &head_a);
	ft_printf("pa\n");
}*/

/*void	pb(t_dnode **head_a, t_dnode **head_b)
//void	pb(t_dnode *head_a, t_dnode *head_b)
{
//	push(&head_a, &head_b);
	push(head_a, head_b);
	ft_printf("pb\n");
}*/

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