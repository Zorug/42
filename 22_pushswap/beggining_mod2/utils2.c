# include "push_swap.h"

void	print_both(t_dnode *head_a, t_dnode *head_b)
{
	ft_printf("A:\n");
	print_list_foward(head_a);
	ft_printf("B:\n");
	print_list_foward(head_b);
	ft_printf("\n");
}

void	do_stuff(t_dnode *head_a, t_dnode *head_b)
{
	print_both(head_a, head_b);
	pb(&head_a, &head_b);
	//pb(&head_a, &head_b);
	//pb(&head_a, &head_b);
	//pb(&head_a, &head_b);
	print_both(head_a, head_b);

	/*sa(&head_a);
	sb(&head_b);
	print_both(head_a, head_b);
	ss(&head_a, &head_b);
	print_both(head_a, head_b);

	ra(&head_a);
	rb(&head_b);
	print_both(head_a, head_b);
	rr(&head_a, &head_b);
	print_both(head_a, head_b);

	rra(&head_a);
	rrb(&head_b);
	print_both(head_a, head_b);
	rrr(&head_a, &head_b);
	print_both(head_a, head_b);*/
}