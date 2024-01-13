/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:28:36 by ysemlali          #+#    #+#             */
/*   Updated: 2024/01/12 23:37:44 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	if (b)
	{
		tmp = b->next;
		b->next = a;
		a = b;
		b = tmp;
	}
}

void	pb(t_stack *a, t_stack *b)
{
	int	*tmp;

	if (a)
	{
		tmp = a->next;
		a->next = b;
		b = a;
		a = tmp;
	}
}
