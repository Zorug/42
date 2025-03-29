/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:10:20 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/30 07:40:09 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// usage:
// #include "../libft.h"

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h> // size_t, malloc(), free()
# include <unistd.h> // write(), read()
# include <stdarg.h> // variatic func.

// Personal function
char	*ad_malloc_cat(const char *s1, const char *s2);
char	*ad_malloc_cat_and_free(char *s1, char *s2);
char	*ad_malloc_cat_prefix_and_free_string(const char *s1, char *s2);

char	*ad_rm_chr(char const *str, char const *set);

void	free_array(char **arr);

// Reimplemented function
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strrchr(const char *s, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_atoi(const char *nptr);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);

// Aditional function
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);

// Bonus functions (list)
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//ft_printf
int		ft_printf(const char *initial_str, ...);
void	printf_integer(char *conv_str, int *count, va_list ptr_args);
void	printf_character(char *conv_str, int *count, va_list ptr_args);
void	printf_string(char *conv_str, int *count, va_list ptr_args);
void	printf_unsigned_integer(char *conv_str, int *count, va_list ptr_args);
void	printf_unsigned_d(char *conv_str, int *count, va_list ptr_args);
char	*ft_ultoa(unsigned long nbr, unsigned int radix);
void	printf_hex_lower(char *conv_str, int *count, va_list ptr_args);
void	printf_hex_upper(char *conv_str, int *count, va_list ptr_args);
void	printf_pointer(char *conv_str, int *count, va_list ptr_args);
void	ft_format_alternate(char *conv_str, char **str);
size_t	ft_format_width(char *conv_str, char **str);
void	ft_format_precision_string(char *conv_str, char **str);
void	ft_format_precision_numeric(char *conv_str, char **str);
void	ft_format_precision_hexadecimal(char *conv_str, char **str);
int		ft_hextoi(char *hex_str);
char	ft_format_place_sign(char *conv_str, char **str);

//get_next_line
// pre-defines BUFFER_SIZE to 42
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
//char	*ft_strchr(const char *s, int c);
char	*gnl_strjoin(char *s1, char const *s2);
//size_t	ft_strlen(const char *str);
//char	*ft_strdup(const char *s);

#endif
