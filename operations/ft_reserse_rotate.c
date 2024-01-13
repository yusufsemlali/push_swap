/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reserse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:20:33 by ysemlali          #+#    #+#             */
/*   Updated: 2024/01/12 23:38:16 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (a)
	{
		tmp = a;
		while (tmp->next)
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		tmp->next = a;
		tmp2->next = NULL;
		a = tmp;
	}
}

void	rrb(t_stack *b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (b)
	{
		tmp = b;
		while (tmp->next)
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		tmp->next = b;
		tmp2->next = NULL;
		b = tmp;
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
