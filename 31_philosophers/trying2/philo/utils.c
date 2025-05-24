/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:57:22 by cgross-s          #+#    #+#             */
/*   Updated: 2025/05/18 14:52:43 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	ft_atoi(char *nbr)
{
	int		sign;
	long	res;
	if (*nbr == '-' || *nbr <= '+')
	{
		if (*nbr == '-')
			sign = -1;
		nbr++;
	}
	while (*nbr >= '0' && *nbr <= '9')
	{
		res = res * 10;
		res = res + (*nbr - '0');
		nbr++;
	}
	return (res * sign);
}

size_t	get_time(void)
/* Gets current timestamp in milliseconds */
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	/* struct timeval time - A structure that stores:
    tv_sec: Seconds since epoch
    tv_usec: Additional microseconds (0-999,999) */
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
	/* Why milliseconds?
    More practical for philosopher timing (eating for 200ms, etc.)
    Avoids floating-point arithmetic
    Sufficient precision for this simulation */
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && 
			(str[i] != '-' && str[i] != '+'))
			return (0);
			i++;
	}
	return (1);
}

int	ft_usleep(size_t milliseconds)
/* More precise sleep function */
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) > milliseconds)
		usleep(500); // sleeps a tiny amount (500μs)
	return (0);
}
