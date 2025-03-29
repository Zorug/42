#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

// Estrutura do nó da lista encadeada
typedef struct	s_dnode {
	int				value;
	struct s_dnode	*next;
	struct s_dnode	*prev;
}	t_dnode;

t_dnode	*create_node(int value);
void	append_node(t_dnode **stack, int nbr);
void	append_node_prev(t_dnode **head, int value);
void	print_list_foward(t_dnode *head);
void	print_list_backward(t_dnode * tail);
void	free_list(t_dnode *head);

void    free_split(char **argv, bool flag_splt, int word_pos);

bool	is_number(char *str);
bool	is_unique(t_dnode *head_a, int nbr);

//void	swap_a(t_dnode *head);
void	swap(t_dnode **head);
//void	swap(t_dnode *head);
//void	rotate(t_dnode *head);
void	rotate(t_dnode **head);
//void	rev_rotate(t_dnode *head);
void	rev_rotate(t_dnode **head);
//void	rev_rotate_a(t_dnode *head);
//void	push_b(t_dnode **head_a, t_dnode **head_b);
void	push(t_dnode **head_src, t_dnode **head_dst);
//void	push_b(t_dnode *head_a, t_dnode *head_b);
//void	push_b(t_dnode *head_a);

//void	ra(t_dnode *head_a);
//void	rb(t_dnode *head_b);
//void	rr(t_dnode *head_a, t_dnode *head_b);
void	ra(t_dnode **head_a);
void	rb(t_dnode **head_b);
void	rr(t_dnode **head_a, t_dnode **head_b);

//void	rra(t_dnode *head_a);
//void	rrb(t_dnode *head_b);
//void	rrr(t_dnode *head_a, t_dnode *head_b);
void	rra(t_dnode **head_a);
void	rrb(t_dnode **head_b);
void	rrr(t_dnode **head_a, t_dnode **head_b);

//void	sa(t_dnode *head_a);
void	sa(t_dnode **head_a);
//void	sb(t_dnode *head_b);
void	sb(t_dnode **head_b);
//void	ss(t_dnode *head_a, t_dnode *head_b);
void	ss(t_dnode **head_a, t_dnode **head_b);

void	pa(t_dnode **head_a, t_dnode **head_b);
//void	pa(t_dnode *head_a, t_dnode *head_b);
void	pb(t_dnode **head_b, t_dnode **head_a);
//void	pb(t_dnode *head_b, t_dnode *head_a);

void	do_stuff(t_dnode *head_a, t_dnode *head_b);
void	print_both(t_dnode *head_a, t_dnode *head_b);

t_dnode	*find_last_node(t_dnode *head);

void	error_free(t_dnode **a, char **argv, bool flag_argc_2);
void	free_stack(t_dnode **stack);
void	free_matrix(char **argv);

int	stack_len(t_dnode *stack);

# endif