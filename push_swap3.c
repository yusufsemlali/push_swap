/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:22:46 by ysemlali          #+#    #+#             */
/*   Updated: 2024/06/08 13:34:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_arg(int ac, char **av)
{
	int	i;
	int	x;

	i = 1;
	while (i < ac)
	{
		x = 0;
		if (av[i][x] == '-')
			x++;
		while (av[i][x])
		{
			if (!ft_isdigit(av[i][x]))
				return (0);
			x++;
		}
		i++;
	}
	return (1);
}

int	ft_check_doubles(int ac, char **av)
{
	int		i;
	int		j;
	long	*tab;

	i = 1;
	tab = malloc(sizeof(long) * ac - 1);
	while (i < ac)
	{
		tab[i - 1] = ft_atoi(av[i]);
		if (tab[i - 1] > INT_MAX || tab[i - 1] < INT_MIN)
			return (free(tab), 0);
		i++;
	}
	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (tab[i] == tab[j])
				return (free(tab), 0);
			j++;
		}
		i++;
	}
	free(tab);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		if (!ft_check_arg(ac, av) || !ft_check_doubles(ac, av))
		{
			write(1, "Error", 5);
			return (0);
		}
		else
			ft_push_swap(ac, av);
		// write(1, "OK", 2);
	}
	// system("leaks push_swap");
}