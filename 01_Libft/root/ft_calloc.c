/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:57:43 by cgross-s          #+#    #+#             */
/*   Updated: 2024/11/02 19:57:44 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
The calloc() function allocates memory for an array of 
nmemb elements of size bytes each and returns a pointer
to  the  allocated  memory.
The  memory is set to zero.  
If nmemb or size is 0, then calloc() returns either NULL, 
or a unique pointer value that can later  be  successfully  
passed to free().  
If the multiplication of nmemb and size would result in 
integer overflow, then calloc() returns an error.  
By contrast, an integer overflow would not be detected in 
the following call to malloc(), with the result that an 
incorrectly sized block of memory would be allocated:

malloc(nmemb * size);
*/
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	else
		ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
The malloc() and calloc() functions return a pointer to 
the allocated memory, which is suitably aligned for any 
built-in type.
On  error, these functions return NULL. 
NULL may also be returned by a successful call to malloc()
with a size of zero, or by a successful call to calloc() 
with nmemb or size equal to zero.
*/