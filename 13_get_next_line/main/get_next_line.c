#include "get_next_line.h"

/*Polish linked list for next call*/
void	polish_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (NULL == buf || NULL == clean_node)
		return ;
	last_node = find_last_node(*list);

	i = 0;
	k = 0;
	while (last_node->str_buf[i] != '\0'
		&& last_node->str_buf[i] != '\n')
		++i;
	//		is it != '\0'? -> '\n'
	while (last_node->str_buf[i] != '\0'
		&& last_node->str_buf[++i])
		buf[k++] = last_node->str_buf[i];
	buf[k] = '\0';
	clean_node->str_buf = buf;
	clean_node->next = NULL;
	dealloc(list, clean_node, buf);
}

/*Get my (line\n)*/
char	*get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (NULL == list)
		return (NULL);

	// Count how many char are till '\n'
	// So i know how much to malloc
	str_len = len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (NULL == next_str)
		return (NULL);

	//Copy the string in the buffer and return it 
	copy_str(list, next_str);
	return (next_str);
}

/*append one node to the end of list*/
// void	append(t_list **list, char *buf)
void	append(t_list **list, char *buf, int fd)
{
	t_list	*new_node;
	t_list	*last_node;

	//last_node = find_last_node(*list);
	last_node = find_last_node(list[fd]);
	new_node = malloc(sizeof(t_list));
	if (NULL == new_node)
		return ;
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
	//while (!found_newline(*list))
	while (!found_newline(list[fd]))
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
		// append(list, buf);
		append(list, buf, fd);
	}
}

/*
Mother function
took a fildes
gives back the next_string
*/
char	*get_next_line(int fd)
{
	//static t_list	*list = NULL;
	static t_list	*list[4096];
	char			*next_line;

	//fd are only positives | read gives -1 if some problems on reading
	//if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);

	//Create my list till i stumble into '\n'
	create_list(list, fd);

	if (list == NULL)
		return (NULL);

	//fetch the line from list
	//next_line = get_line(list);
	next_line = get_line(list[fd]);

	//polish_list(&list);
	polish_list(&list[fd]);
	return (next_line);
}
