/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:58:41 by cgross-s          #+#    #+#             */
/*   Updated: 2025/01/12 20:03:43 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * The function reads data from a file descriptor and appends it to a stash 
 * until a newline character is found or the end of the file is reached.
 */
/*search buffersize chars by buffsize untill finds \n inside buffer*/
static char	*read_and_stash(int fd, char *stash)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (buffer);
			free (stash);
			return (NULL);
		}
		buffer[bytes] = '\0';
		if (!buffer)
			return (NULL);
		stash = ft_strjoin(stash, buffer);
	}
	free (buffer);
	return (stash);
}
/*
 * The function "extract_line" takes a string as input and returns a new string 
 * containing the characters up to the first newline character, including the 
 * newline character if it exists.
 * 
 * @param stash The `stash` parameter is a pointer to a string that contains 
 * multiple lines of text.
 * 
 * @return a pointer to a string that represents a line  extracted from the 
 * input string "stash".
 */

static char	*extract_line(char *stash)
{
	char	*line;
	size_t	i;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + (stash[i] == '\n') + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

/*
 * The function "clean_stash" removes the first line from a string and returns 
 * the modified string.
 * 
 * @param stash The parameter "stash" is a pointer to a string that needs to be
 * cleaned.
 * 
 * @return a pointer to a new string that is a cleaned version of the input 
 * string "stash".
 */
static char	*clean_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*new_stash;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!new_stash)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

/*
 * The function "get_next_line" reads a line from a file descriptor and returns 
 * it as a string.
 * 
 * @param fd The parameter "fd" stands for file descriptor. It is an integer 
 * value that represents an open file in the operating system. In this context, 
 * it is used to specify the file from which the function should read the next 
 * line.
 * 
 * @return a string, which represents the next line read from the file 
 * descriptor specified by `fd`.
 */
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}

/*int	main()
{
	int		fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Erro opening the file");
		return (1);
	}
    while ((str = get_next_line(fd)) != NULL)
    {
        printf("%s", str);
        free(str); // Free each line after use
    }
	close (fd);
	return (0);
}*/
/*
cc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
*/