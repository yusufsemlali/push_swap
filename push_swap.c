/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:22:46 by ysemlali          #+#    #+#             */
/*   Updated: 2024/01/13 02:11:11 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>

int	ft_check_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-')
			j++;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_doubles(int ac, char **av)
{
	int	i;
	int	j;
	int	*tab;

	i = 1;
	tab = ft_calloc(sizeof(int) , ac);
	while (i < ac)
	{
		tab[i] = ft_atoi(av[i]);
		i++;
	}
	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		if (ac <= 1)
			return (0);
		else
		{
			if (ft_check_arg(ac, av) == 0)
			{
				write(2, "args are not valid\n", 19);
				return (0);
			}
			if (ft_check_doubles(ac, av) == 0)
			{
				write(2, "doubles are not allowed\n", 24);
				return (0);
			}
			// else
			// ft_push_swap(ac, av);
		}
	}
}
