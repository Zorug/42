/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:49:52 by cgross-s          #+#    #+#             */
/*   Updated: 2025/04/23 21:41:56 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdint.h>
//# include "ft_printf.h"

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

size_t	ft_strlen(const char *s);

void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

int		ft_toupper(int c);
int		ft_tolower(int c);

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);

void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len);

//char	*ft_strjoin(char const *s1, char const *s2);
//char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

double	ft_atof(const char *nptr);
char	*read_line(void);

int		ft_putstr(char *str);
int		ft_putchar(int c);
int		ft_putnbr_base(unsigned long n, char *base_to);
int		ft_putptr(void *ptr);
int		ft_putnbr(int n);
int		ft_putnbr_unsigned(unsigned int n);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

# define BUFFER_SIZE 10

typedef struct s_read_line //complemento de ft_read_line.c
{
	char	*buffer;
	char	temp[BUFFER_SIZE + 1];
	char	*new_buffer;
	int		total_len;
	int		bytes_read;
	int		i;
	bool	block;
}	t_rdline;

int		ft_printf(const char *format, ...);

#endif