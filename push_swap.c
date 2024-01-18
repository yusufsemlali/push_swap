/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:22:46 by ysemlali          #+#    #+#             */
/*   Updated: 2024/01/17 11:01:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>


int	ft_check_arg(int ac, char **av)
{
	int i = 1;
	int x;

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
    int	i;
    int	j;
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
	if (ac > 2)
	{
		if (!ft_check_arg(ac -1 , av) || !ft_check_doubles(ac, av))
			{
				write(1, "Error", 5);
				return (0);
			}
		else
			ft_push_swap(ac , av);
			// write(1, "OK", 2);
	}
	// system("leaks push_swap");
}

/* 
While stack A is not sorted:
    Find the smallest element in stack A using ra operation
    Move the smallest element to the top of stack A using rra operation
    Push the smallest element to stack B using pb operation
    If the top two elements of stack B are in the wrong order:
        Swap them using sb operation
    If the top two elements of both stacks are in the wrong order:
        Swap them using ss operation
    Rotate stack A and B using rr operation
    Reverse rotate stack A and B using rrr operation
While stack B is not empty:
    Push the top element of stack B back to stack A using pa operation
*/



/*
function quicksort(a, b):
    if a is empty:
        return
    pivot = choose_pivot(a)
    move_elements_less_than_pivot_to_b(a, b, pivot)
    move_elements_greater_than_or_equal_to_pivot_to_a(a, b, pivot)
    quicksort(a, b)
    quicksort(b, a)
*/