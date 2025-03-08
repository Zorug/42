/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:17:26 by cgross-s          #+#    #+#             */
/*   Updated: 2025/03/08 21:00:22 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

#define BUFFER_SIZE 10

typedef struct s_read_line
{
	char	*buffer;
	char	temp[BUFFER_SIZE + 1];
	char	*new_buffer;
	int		total_len;
	int		bytes_read;
	int		i;
	bool	block;
}	t_rdline;

void	rl_complement(t_rdline *rl)
{
	rl->buffer = rl->new_buffer;
	rl->i = 0;
	while (rl->i < rl->bytes_read)
	{
		rl->buffer[rl->total_len + rl->i] = rl->temp[rl->i];
		if (rl->temp[rl->i] == '\n')
		{
			rl->buffer[rl->total_len + rl->i + 1] = '\0';
			rl->block = true;
			return ;
		}
		rl->i++;
	}
}

char	*read_line(void)
{
	t_rdline	rl;

	rl.buffer = NULL;
	rl.total_len = 0;
	rl.bytes_read = read(0, rl.temp, BUFFER_SIZE);
	rl.block = false;
	while (rl.bytes_read > 0 && rl.block == false)
	{
		rl.temp[rl.bytes_read] = '\0';
		rl.new_buffer = realloc(rl.buffer, rl.total_len + rl.bytes_read + 1);
		if (!rl.new_buffer)
		{
			free(rl.buffer);
			return (NULL);
		}
		rl_complement(&rl);
		if (rl.block == false)
		{
			rl.total_len += rl.bytes_read;
			rl.buffer[rl.total_len] = '\0';
			rl.bytes_read = read(0, rl.temp, BUFFER_SIZE);
		}
	}
	return (rl.buffer);
}


int ft_strcnt(char *str)
{
	int i;
	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

int main()
{
	char *str0;// = "Digite algo: ";
	char *input;

	str0 = "Digite algo: ";
	write(1, str0, ft_strcnt(str0));
	//char *input = read_line();
	input = read_line();
	
	if (input)
	{
		printf("Você digitou: %s", input);
		free(input); // Libera a memória alocada
	}
	else
	{
		printf("Erro ao ler entrada!\n");
	}

	return 0;
}
