# include <stdio.h>
# include <stdlib.h>

// Estrutura do nó da lista encadeada
typedef struct	s_dnode {
	int				value;
	struct s_dnode	*next;
	struct s_dnode	*prev;
}	t_dnode;

// Função para criar um novo nó
t_dnode	*create_node(int value) 
{
	t_dnode	*new_node = (t_dnode *)malloc(sizeof(t_dnode));
	if (!new_node)
	{
		printf("Erro ao alocar memória\n");
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
	printf("Lista (crescente): ");
	while (head)
	{
		printf("%d -> ", head->value);
		if (!head->next) break; // Guarda o último nó para a impressão reversa
		head = head->next;
	}
	printf("NULL\n");
}

void	print_list_backward(t_dnode * tail)
{
	printf("lista (reversa): NULL ");
	while (tail)
	{
		printf("<- %d ", tail->value);
		tail = tail->prev;
	}
	printf("\n");
}

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

int	main ()
{
	t_dnode	*head = NULL;

	append_node(&head, 10);
	append_node(&head, 20);
	append_node(&head, 30);
	append_node(&head, 40);

	print_list_foward(head);
	//printf("Lista encadeada:\n");
	//print_list(head);

	// Encontrar o último nó para impressão reversa
	t_dnode *tail = head;
	while (tail->next)
		tail = tail->next;
	print_list_backward(tail);

	free_list(head);

	return (0);

}