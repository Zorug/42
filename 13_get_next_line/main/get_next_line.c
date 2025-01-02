#include "get_next_line.h"

/*append one node to the end of list*/
void	append(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (NULL == new_node)
		return;
	// if the list is empty
	// if null == *list
	if (NULL == last_node)
		*list = new_node;
	else
		last_node->next = new_node;

	new_node->str_buf = buf;
	new_node->next = NULL;
}


void	create_list(t_list **list, int fd)
{
	//Necessary to place the \0 -> "string\0";
	int		char_read;
	char	*buf;

	// scan line if '\n' present
	while (!found_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (NULL == buf)
			return;
									//10
		char_read = read(fd, buf, BUFFER_SIZE);
		//	EOF
		if (!char_read)
		{
			free(buf);
			return;
		}
		buf[char_read] = '\0';
		// Append the node
		append(list, buf);
	}
}

/*
Mother function
took a fildes
gives back the next_string
*/
char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	//fd are only positives | read gives -1 if some problems on reading
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);

	//Create my list till i stumble into '\n'
	create_list(&list, fd);

	if (list == NULL)
		return (NULL);

	//fetch the line from list
	next_line = get_line(list);

	polish_list(&list);
	return(next_line);
}