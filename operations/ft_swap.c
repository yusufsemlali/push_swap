/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:26:35 by ysemlali          #+#    #+#             */
/*   Updated: 2024/05/14 18:36:36 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

void	sa(t_stack **a, int p)
{
	int	tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->number;
		(*a)->number = (*a)->next->number;
		(*a)->next->number = tmp;
	}
	if (p)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int p)
{
	int	tmp;

	if (*b && (*b)->next)
	{
		tmp = (*b)->number;
		(*b)->number = (*b)->next->number;
		(*b)->next->number = tmp;
	}
	if (p)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}
