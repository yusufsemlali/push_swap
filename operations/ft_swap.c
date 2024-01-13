/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:26:35 by ysemlali          #+#    #+#             */
/*   Updated: 2024/01/12 23:38:10 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// t_stack members are; number and next.
void	sa(t_stack *a)
{
	int	tmp;

	if (a && a->next)
	{
		tmp = a->number;
		a->number = a->next->number;
		a->next->number = tmp;
	}
}

void	sb(t_stack *b)
{
	int	tmp;

	if (b && b->next)
	{
		tmp = b->number;
		b->number = b->next->number;
		b->next->number = tmp;
	}
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
