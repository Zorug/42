# include "push_swap.h"

// Função para criar um novo nó
/*t_dnode	*create_node(int value)
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
}*/

// Função para adicionar um nó ao final da lista
/*void	append_node(t_dnode **stack, int nbr)
{
	t_dnode	*new_node;// = create_node(value);
	t_dnode *temp;// = *stack;

	new_node = create_node(nbr); //fez um malloc
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
	//free_list(temp);
}*/

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

/*
void	print_list_backward(t_dnode * tail)
{
	ft_printf("lista (reversa): NULL ");
	while (tail)
	{
		ft_printf("<- %d ", tail->value);
		tail = tail->prev;
	}
	ft_printf("\n");
}*/
/*
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
*/
void	free_matrix(char **argv)
{
	int	i;

	if (argv == NULL || *argv == NULL)
		return ;
	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
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