#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista encadeada
typedef struct	s_node {
	int				value;
	struct s_node	*next;
}	t_node;

// Função para criar um novo nó
t_node	*create_node(int value) 
{
	t_node	*new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		printf("Erro ao alocar memória");
		exit(1);
	}
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

// Função para adicionar um nó ao final da lista
void	append_node(t_node **head, int value)
{
	t_node	*new_node = create_node(value);
	if (!*head)
	{
		*head =new_node;
		return ;
	}
	t_node *temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}

// Função para imprimir a lista
void	print_list(t_node *head)
{
	while (head)
	{
		printf("%d -> ", head->value);
		head = head->next;
	}
	printf("NULL\n");
}

// Função para liberar a memória da lista
void	free_list(t_node *head)
{
	t_node *temp;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

int	main ()
{
	t_node	*head = NULL;

	append_node(&head, 10);
	append_node(&head, 20);
	append_node(&head, 30);
	append_node(&head, 40);

	printf("Lista encadeada:\n");
	print_list(head);

	free_list(head);

	return (0);

}