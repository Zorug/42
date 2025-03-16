#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>

// Estrutura do nó da lista encadeada
typedef struct	s_dnode {
	int				value;
	struct s_dnode	*next;
	struct s_dnode	*prev;
}	t_dnode;

t_dnode	*create_node(int value);
void	append_node(t_dnode **head, int value);
void	print_list_foward(t_dnode *head);
void	print_list_backward(t_dnode * tail);
void	free_list(t_dnode *head);

void    free_split(char **argv, bool flag_splt, int word_pos);

# endif