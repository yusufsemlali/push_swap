/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:20:32 by ysemlali          #+#    #+#             */
/*   Updated: 2024/01/12 23:29:23 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (a)
	{
		tmp = a->next;
		tmp2 = a;
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = a;
		a->next = NULL;
		a = tmp;
	}
}

void	rb(t_stack *b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (b)
	{
		tmp = b->next;
		tmp2 = b;
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = b;
		b->next = NULL;
		b = tmp;
	}
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
