/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:20:33 by ysemlali          #+#    #+#             */
/*   Updated: 2024/07/08 09:02:22 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

void	rra(t_stack **a, int p)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*a)
	{
		tmp = *a;
		while (tmp->next)
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		tmp->next = *a;
		tmp2->next = NULL;
		*a = tmp;
		if (p)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **b, int p)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*b)
	{
		tmp = *b;
		while (tmp->next)
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		tmp->next = *b;
		tmp2->next = NULL;
		*b = tmp;
		if (p)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}
