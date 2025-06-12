#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
		if (*s++ == (char)c)
			return ((char *)(s - 1));
	return (NULL);
}

static size_t	ft_strlen(const char *s)
{
	size_t len = 0;
	while (s && s[len])
		len++;
	return (len);
}

static char	*ft_strdup(const char *s1)
{
	size_t	len = ft_strlen(s1);
	char	*dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	for (size_t i = 0; i < len; i++)
		dup[i] = s1[i];
	dup[len] = '\0';
	return (dup);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1 = ft_strlen(s1);
	size_t	len2 = ft_strlen(s2);
	char	*res = malloc(len1 + len2 + 1);
	if (!res)
		return (free(s1), NULL);
	for (size_t i = 0; i < len1; i++)
		res[i] = s1[i];
	for (size_t j = 0; j < len2; j++)
		res[len1 + j] = s2[j];
	res[len1 + len2] = '\0';
	free(s1);
	return (res);
}

static char	*extract_line(char **stash)
{
	char	*newline = ft_strchr(*stash, '\n');
	char	*line;
	char	*remaining;
	size_t	len;

	if (!*stash || !**stash)
		return (free(*stash), *stash = NULL, NULL);
	if (newline)
	{
		len = newline - *stash + 1;
		line = malloc(len + 1);
		if (!line)
			return (NULL);
		for (size_t i = 0; i < len; i++)
			line[i] = (*stash)[i];
		line[len] = '\0';
		remaining = ft_strdup(*stash + len);
		free(*stash);
		*stash = remaining;
	}
	else
	{
		line = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(stash), stash = NULL, NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		if (!stash)
			stash = ft_strdup("");
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (NULL);
	}
	return (extract_line(&stash));
}
