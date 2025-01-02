# ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

/*
node of the link list
*/

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}	t_list;



# endif GET_NEXT_LINE_H