/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:51:18 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:03 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Function name
//		ft_lstnew
//	Prototype
//		t_list *ft_lstnew(void *content);
//	Turn in files
//		-
//	Parameters
//		content: The content to create the node with.
//	Return value
//		The new node
//	External functs.
//		malloc
//	Description
//		Allocates (with malloc(3)) and returns a new node. The member variable
//	’content’ is initialized with the value of the parameter ’content’. The
//	variable ’next’ is initialized to NULL.

#include "../libft.h"
//  t_list, ft_calloc()
//  void	*ft_calloc(size_t nmemb, size_t size)

t_list	*ft_lstnew(void *content)
{
	t_list	*first;

	first = (t_list *) malloc(sizeof(t_list));
	if (first == NULL)
		return (NULL);
	(*first).content = content;
	(*first).next = NULL;
	return (first);
}
