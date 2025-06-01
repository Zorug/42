#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

size_t	ft_strlen(const char *s)
{
	size_t i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	len1 = ft_strlen(s1), len2 = ft_strlen(s2), i = 0, j = 0;
	char	*res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	if (s1)
		free(s1);
	return (res);
}

void	ft_strcpy(char *dst, const char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1] = {0};
	char		*line = NULL, *nl;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		nl = ft_strchr(buf, '\n');
		if (nl) // encontrou o \n?
		{
			nl++; // move o ponteiro para depois do '\n'
			char tmp = *nl; // salva o próximo caractere
			*nl = '\0'; // quebra a string após o '\n'
			line = ft_strjoin(line, buf); // junta essa parte ao resultado
			*nl = tmp; // restaura o caractere modificado
			ft_strcpy(buf, nl); // move o restante do buffer para o começo
			return (line); // retorna a linha pronta
		}
		line = ft_strjoin(line, buf); // Junta o conteúdo completo do buffer à linha parcial.
		bytes = read(fd, buf, BUFFER_SIZE); // Lê mais dados do arquivo e armazena no buffer.
		if (bytes <= 0) // read retornou erro (-1) ou EOF (0).
		{
			if (bytes < 0 || !line || !*line) // em caso de erro ou linha vazia
				return (free(line), NULL);
			buf[0] = '\0'; // Se havia dados parciais na line, retorna o que conseguiu montar (sem \n no final).
			return (line);
		}
		buf[bytes] = '\0'; // Garante que o buffer lido termine com \0, tornando-o uma string C válida.
	}
}
