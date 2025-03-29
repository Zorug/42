/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:20:57 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:51:52 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Function name
//		get_next_line
//	Prototype
//		char *get_next_line(int fd);
//	Turn in files
//		get_next_line.c, get_next_line_utils.c,
//		get_next_line.h
//	Parameters
//		fd: The file descriptor to read from
//	Return value
//		Read line: correct behavior
//		NULL: there is nothing else to read, or an error occurred
//	External functs.
//		read, malloc, free
//	Description
//		Write a function that returns a line read from a file descriptor

#include "../libft.h"

char	*write_to_mem(int fd, char *permanent_mem);
char	*get_current_line(char *permanent_mem);
char	*trim_memory(char *permanent_mem);

char	*get_next_line(int fd)
{
	static char	*permanent_mem[101010];
	char		*current_line;
	size_t		i;

	if (BUFFER_SIZE < 1 || BUFFER_SIZE > 10000000 || fd < 0 || fd >= 101010)
		return (NULL);
	if (permanent_mem[fd] == NULL)
	{
		permanent_mem[fd] = malloc(sizeof(char) * BUFFER_SIZE);
		if (!permanent_mem[fd])
			return (NULL);
		i = 0;
		while (i < BUFFER_SIZE)
			permanent_mem[fd][i++] = '\0';
	}
	permanent_mem[fd] = write_to_mem(fd, permanent_mem[fd]);
	current_line = get_current_line(permanent_mem[fd]);
	permanent_mem[fd] = trim_memory(permanent_mem[fd]);
	return (current_line);
}

// ssize_t	read(int fd, void *buf, size_t count);
char	*write_to_mem(int fd, char *permanent_mem)
{
	ssize_t	read_return;
	char	*current_line;

	current_line = malloc(BUFFER_SIZE + 1);
	if (current_line == NULL)
		return (NULL);
	read_return = 1;
	while (read_return > 0 && !ft_strchr(permanent_mem, '\n'))
	{
		read_return = read(fd, current_line, BUFFER_SIZE);
		if (read_return == -1)
		{
			free(current_line);
			free(permanent_mem);
			return (NULL);
		}
		if (read_return == 0)
			break ;
		current_line[read_return] = '\0';
		permanent_mem = gnl_strjoin(permanent_mem, current_line);
	}
	free(current_line);
	return (permanent_mem);
}

char	*get_current_line(char *permanent_mem)
{
	char	*current_line;
	size_t	i;
	size_t	j;

	if (permanent_mem == NULL || permanent_mem[0] == '\0')
		return (NULL);
	i = 0;
	while (permanent_mem[i] != '\n' && permanent_mem[i])
		i++;
	current_line = malloc(sizeof(char) * (i + 2));
	if (!current_line)
		return (NULL);
	j = 0;
	while (j < i + 1)
	{
		current_line[j] = permanent_mem[j];
		j++;
	}
	current_line[j] = '\0';
	return (current_line);
}

char	*trim_memory(char *permanent_mem)
{
	char	*next_line;
	size_t	len;

	len = 0;
	if (!permanent_mem)
		return (NULL);
	while (permanent_mem[len] != '\0' && permanent_mem[len] != '\n')
		len++;
	if (!permanent_mem[len])
		return (free(permanent_mem), NULL);
	next_line = ft_strdup(permanent_mem + len + 1);
	free(permanent_mem);
	return (next_line);
}
