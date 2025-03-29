/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:07:07 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:02 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// reimplements calloc()

//	NAME
//		calloc - allocate and free dynamic

//	LIBRARY
//		Standard C library (libc, -lc)

//	SYNOPSIS
//		#include <stdlib.h>
//		void *calloc(size_t nmemb, size_t size);

//	DESCRIPTION
//		calloc()
//		The calloc() function allocates memory for an array of nmemb elements
//	of size bytes each and returns a pointer to the allocated memory. The
//	memory is set to zero. If nmemb or size is 0, then calloc() returns a
//	unique pointer value that can later be successfully passed to free().
//	
//		If the multiplication of nmemb and size would result in integer over‐
//	flow, then calloc() returns an error.

//	RETURN VALUE
//		The malloc(), calloc(), realloc(), and reallocarray() functions return
//	a pointer to the allocated memory, which is suitably aligned for any
//	type that fits into the requested size or less. On error, these func‐
//	tions return NULL and set errno. Attempting to allocate more than
//	PTRDIFF_MAX bytes is considered an error, as an object that large could
//	cause later pointer subtraction to overflow.

//	ERRORS
//		calloc(), malloc(), realloc(), and reallocarray() can fail with the
//	following error:

//	ENOMEM Out of memory. Possibly, the application hit the RLIMIT_AS or
//		RLIMIT_DATA limit described in getrlimit(2). Another reason
//		could be that the number of mappings created by the caller
//		process exceeded the limit specified by
//		/proc/sys/vm/max_map_count.

// NOTE
// max size of size_t defined as 2147483648

#include "../libft.h"
// size_t, malloc(), ft_memset(), NULL

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	mem_area;
	void	*mem_ptr;

	if (size > 0 && nmemb > ((2147483648 - 1) / size))
		return (NULL);
	mem_area = nmemb * size;
	mem_ptr = (unsigned char *) malloc(mem_area);
	if (mem_ptr == NULL)
		return (NULL);
	if (mem_area != 0)
		ft_memset(mem_ptr, 0, mem_area);
	return (mem_ptr);
}
