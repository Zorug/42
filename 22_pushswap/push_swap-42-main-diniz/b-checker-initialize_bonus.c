/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b-checker-initialize_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:38:54 by abessa-m          #+#    #+#             */
/*   Updated: 2025/02/05 10:57:28 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	is_valid_int(int argc, char **argv);
static int	is_valid_str(int argc, char **argv);
static int	add_numbers_to_stack(t_ps *ps, char **numbers);

int	initialize_bonus(t_ps *ps, int argc, char **argv, int verbose)
{
	char	**splitted_str;
	int		result;

	ps->verbose = verbose;
	ps->a = NULL;
	ps->b = NULL;
	result = 1;
	if (is_valid_int(argc, argv) == 0)
		result = add_numbers_to_stack(ps, argv + 1);
	else if (is_valid_str(argc, argv) == 0)
	{
		splitted_str = ft_split(argv[1], ' ');
		if (!splitted_str)
			return (2);
		result = add_numbers_to_stack(ps, splitted_str);
		free_array(splitted_str);
	}
	return (result);
}

static int	add_numbers_to_stack(t_ps *ps, char **numbers)
{
	int	i;
	int	*num;

	if (ps->verbose)
		ft_printf("Adding to the bottom of stack a: ");
	i = 0;
	while (numbers[i])
	{
		num = (int *) malloc(sizeof(int) * 1);
		if (!num || numbers[i][0] == '\0')
			return (3);
		*num = ft_atoi(numbers[i]);
		if (ps->verbose)
			ft_printf("%i ", (*num));
		ft_lstadd_back(&ps->a, ft_lstnew(num));
		i++;
	}
	if (ps->verbose)
		ft_printf("\n");
	return (0);
}

static int	is_valid_str(int argc, char **argv)
{
	char	**splitted_str;
	int		i;
	int		j;

	if (argc != 2)
		return (4);
	splitted_str = ft_split(argv[1], ' ');
	if (!splitted_str)
		return (3);
	i = 0;
	while (splitted_str[i])
	{
		if (is_int_bonus(splitted_str[i]) != 0)
			return (free_array(splitted_str), 1);
		j = i + 1;
		while (splitted_str[j])
		{
			if (ft_atoi(splitted_str[i]) == ft_atoi(splitted_str[j]))
				return (free_array(splitted_str), 2);
			j++;
		}
		i++;
	}
	return (free_array(splitted_str), 0);
}

static int	is_valid_int(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		if (is_int_bonus(argv[i]) != 0)
			return (2);
		i++;
	}
	return (0);
}
