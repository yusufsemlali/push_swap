/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemlali <ksemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:20:32 by ysemlali          #+#    #+#             */
/*   Updated: 2024/07/01 14:23:16 by ksemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

void	ra(t_stack **a, int p)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*a)
	{
		tmp = (*a)->next;
		tmp2 = *a;
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = *a;
		(*a)->next = NULL;
		*a = tmp;
	}
	if (p)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int p)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*b && (*b)->next)
	{
		tmp = (*b)->next;
		tmp2 = *b;
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = *b;
		(*b)->next = NULL;
		*b = tmp;
	}
	if (p)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}
