/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 08:06:54 by cgross-s          #+#    #+#             */
/*   Updated: 2025/04/06 08:06:55 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

double	ft_atof(const char *nptr)
{
	double	int_part;
	double	frac_part;
	double	pow;
	int		sign;

	int_part = 0;
	frac_part = 0;
	sign = 1;
	pow = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	while (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			sign = -sign;
	while (*nptr != '.' && *nptr)
		int_part = (int_part * 10) + (*nptr++ - '0');
	if (*nptr == '.')
		nptr++;
	while (*nptr)
	{
		pow /= 10;
		frac_part = frac_part + (*nptr - '0') * pow;
		nptr++;
	}
	return ((int_part + frac_part) * sign);
}

/*int main (int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%f\n", ft_atof(argv[1]));
	}
}*/