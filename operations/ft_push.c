/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:28:36 by ysemlali          #+#    #+#             */
/*   Updated: 2024/07/08 09:02:27 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

void	pa(t_stack **a, t_stack **b, int p)
{
	t_stack	*tmp;

	if (*b)
	{
		tmp = (*b)->next;
		(*b)->next = *a;
		*a = *b;
		*b = tmp;
		if (p)
			write(1, "pa\n", 3);
	}
}

void	pb(t_stack **a, t_stack **b, int p)
{
	t_stack	*tmp;

	if (*a)
	{
		tmp = (*a)->next;
		(*a)->next = *b;
		*b = *a;
		*a = tmp;
		if (p)
			write(1, "pb\n", 3);
	}
}
