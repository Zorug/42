# include "push_swap.h"

// Função para criar um novo nó
t_dnode	*create_node(int value)
{
	t_dnode	*new_node = (t_dnode *)malloc(sizeof(t_dnode));
	if (!new_node)
	{
		ft_printf("Erro ao alocar memória\n");
		exit(1);
	}
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

// Função para adicionar um nó ao final da lista
void	append_node(t_dnode **head, int value)
{
	t_dnode	*new_node = create_node(value);
	if (!*head)
	{
		*head =new_node;
		return ;
	}
	t_dnode *temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
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

void	swap_a(t_dnode *head)
{
	int	value1;
	int	value2;

	value1 = head->value;

	head = head->next;
	value2 = head->value;
	head->value = value1;

	head = head->prev;
	head->value = value2;
}

void	rotate_a(t_dnode *head)
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

void	rev_rotate_a(t_dnode *head)
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
}

/*void	print_list_backward(t_dnode * tail)
{
	ft_printf("lista (reversa): NULL ");
	while (tail)
	{
		ft_printf("<- %d ", tail->value);
		tail = tail->prev;
	}
	ft_printf("\n");
}*/

// Função para liberar a memória da lista
void	free_list(t_dnode *head)
{
	t_dnode *temp;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}