#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = malloc(len1 + len2 + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		new[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		new[len1 + i] = s2[i];
		i++;
	}
	new[len1 + len2] = '\0';
	return (new);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*extract_line(char **buffer)
{
	char	*line;
	char	*newline_pos;
	char	*temp;

	if (!*buffer)
		return (NULL);
	newline_pos = ft_strchr(*buffer, '\n');
	if (!newline_pos)
		return (NULL);
	line = ft_substr(*buffer, 0, (newline_pos - *buffer) + 1);
	temp = ft_strdup(newline_pos + 1);
	free(*buffer);
	*buffer = temp;
	return (line);
}

int	read_to_buffer(int fd, char **buffer)
{
	char	*temp_buffer;
	char	*temp;
	int		read_bytes;

	temp_buffer = malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (-1);
	read_bytes = read(fd, temp_buffer, BUFFER_SIZE);
	if (read_bytes <= 0)
	{
		free(temp_buffer);
		return (read_bytes);
	}
	temp_buffer[read_bytes] = '\0';
	if (!*buffer)
		*buffer = ft_strdup(temp_buffer);
	else
	{
		temp = ft_strjoin(*buffer, temp_buffer);
		free(*buffer);
		*buffer = temp;
	}
	free(temp_buffer);
	return (read_bytes);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = extract_line(&buffer);
	if (line)
		return (line);
	read_bytes = read_to_buffer(fd, &buffer);
	if (read_bytes == -1)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	if (read_bytes == 0)
	{
		if (!buffer || !*buffer)
			return (NULL);
		line = buffer;
		buffer = NULL;
		return (line);
	}
	return (get_next_line(fd));
}