/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:58:22 by cgross-s          #+#    #+#             */
/*   Updated: 2025/01/12 20:03:50 by cgross-s         ###   ########.fr       */
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

	i = 0;
	j = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	i++;
	while (stash[i] != '\0')
	{
		new_stash[j] = stash[i];
		j++;
		i++;
	}
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
	static char	*stash[10000];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_and_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	stash[fd] = clean_stash(stash[fd]);
	return (line);
}

/*int main(void)
{
    int fd1, fd2, fd3;
    char *line;

    // Open multiple files
    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);
    fd3 = open("file3.txt", O_RDONLY);

    if (fd1 < 0 || fd2 < 0 || fd3 < 0)
    {
        perror("Error opening files");
        return (1);
    }

    // Read lines from all file descriptors
    while (1)
    {
        line = get_next_line(fd1);
        if (line)
        {
            printf("File1: %s", line);
            free(line);
        }

        line = get_next_line(fd2);
        if (line)
        {
            printf("File2: %s", line);
            free(line);
        }

        line = get_next_line(fd3);
        if (line)
        {
            printf("File3: %s", line);
            free(line);
        }

        // Exit the loop if all files reach EOF
        if (!line)
            break;
    }

    // Close the files
    close(fd1);
    close(fd2);
    close(fd3);

    return 0;
}*/
/*
cc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
*/