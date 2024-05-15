/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:56:26 by ysemlali          #+#    #+#             */
/*   Updated: 2024/05/14 19:56:51 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

void	ft_sort_small(t_stack **a)
{
	if ((*a)->number > (*a)->next->number)
		ra(a, 1);
	while (!is_sorted(*a))
	{
		if ((*a)->number > (*a)->next->number)
			sa(a, 1);
		else
			rra(a, 1);
	}
}

void	ft_sort_four(t_stack **a, t_stack **b)
{
	int	min;

	min = ft_find_min(*a);
	while (min-- > 0)
		ra(a, 1);
	pb(a, b, 1);
	ft_sort_small(a);
	pa(a, b, 1);
}

void	ft_sort_five(t_stack **a, t_stack **b)
{
	int	smallest;
	int	i;

	i = 0;
	while (i < 2)
	{
		smallest = ft_find_min(*a);
		push_smallest(a, smallest);
		pb(a, b, 1);
		i++;
	}
	ft_sort_small(a);
	pa(a, b, 1);
	pa(a, b, 1);
}
