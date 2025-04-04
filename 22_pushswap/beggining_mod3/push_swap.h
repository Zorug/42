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
	int				push_cost;
	int				index;
	struct s_dnode	*next;
	struct s_dnode	*prev;
	bool			above_median;
	struct s_dnode	*target_node;
	bool			cheapest;
}	t_dnode;

//------- utils1

t_dnode	*find_last_node(t_dnode *head);
//t_dnode	*create_node(int value);
//void	append_node(t_dnode **stack, int nbr);
//void	append_node_prev(t_dnode **head, int value);
void	print_list_foward(t_dnode *head);
//void	print_list_backward(t_dnode * tail);
void	print_cost(t_dnode *head);
void	print_target(t_dnode *head);
int	stack_len(t_dnode *stack);

//------- utils2

bool	is_number(char *str);
bool	is_unique(t_dnode *head_a, int nbr);
//void	print_both(t_dnode *head_a, t_dnode *head_b);
void	print_both(t_dnode *a, t_dnode *b, void (*func)(t_dnode *));
t_dnode	*get_cheapest(t_dnode *stack);
void	prep_for_push(t_dnode **stack, t_dnode *top_node,
	char stack_name);
void	sort_three(t_dnode **a);
//void	do_stuff(t_dnode **a);
void	do_stuff(t_dnode **a, t_dnode **b);
//void	do_stuff(t_dnode *a);
//void	do_stuff(t_dnode *head_a, t_dnode *head_b);
//void	do_stuff(t_dnode *head_a);

//---- utils3
void	ft_stackadd_front(t_dnode **stack, t_dnode *new);
t_dnode	*ft_stack_new(long content);
t_dnode	*ft_stack_last(t_dnode *stack);
void	ft_stackadd_back(t_dnode **stack, t_dnode *new);
int	argv_cnt(char **argv);
t_dnode	*get_stack(int argc, char **argv);
void	ft_sort(t_dnode **a);
//void	ft_sort(t_dnode *a);

//--- utils4
void	rotate_both(t_dnode **a, t_dnode **b,
	t_dnode *cheapest_node);
void	rev_rotate_both(t_dnode **a, t_dnode **b,
	t_dnode *cheapest_node);
void	move_a_to_b(t_dnode **a, t_dnode **b);
void	move_b_to_a(t_dnode **a, t_dnode **b);
void	min_on_top(t_dnode **a);

//--- utils5
void	current_index(t_dnode *stack);
t_dnode	*find_max(t_dnode *stack);
void	set_target_a(t_dnode *a, t_dnode *b);
t_dnode	*find_min(t_dnode *stack);
void	set_target_b(t_dnode *a, t_dnode *b);
void	cost_analysis_a(t_dnode *a,t_dnode *b);
void	set_cheapest(t_dnode *stack);
void	init_nodes_a(t_dnode *a, t_dnode *b);
void	init_nodes_b(t_dnode *a, t_dnode *b);

//--- utils_free
void	ft_free(void *x);
void	ft_stackclear(t_dnode **stack, void (*del)(void*));
void	free_matrix(char **argv);
void	free_stack(t_dnode **stack);
void	error_free(t_dnode **a, char **argv, bool flag_argc_2);





//void	free_list(t_dnode *head);

//void    free_split(char **argv, bool flag_splt, int word_pos);

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
//void	rra(t_dnode **head_a, bool print_ft);
//void	rrb(t_dnode **head_b, bool print_ft);
//void	rrr(t_dnode **head_a, t_dnode **head_b, bool print_ft);

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


//void	push_cost(t_dnode **a, t_dnode **b);


////////
//t_dnode 	current_index(t_dnode *stack);
//////////

//void	print_both_cost(t_dnode *head_a, t_dnode *head_b);

//static void	move_a_to_b(t_dnode **a, t_dnode **b);




//static void	move_b_to_a(t_dnode **a, t_dnode **a);



# endif