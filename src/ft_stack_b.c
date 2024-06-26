/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:10:57 by codespace         #+#    #+#             */
/*   Updated: 2024/06/26 18:42:27by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	getdivisor(m_stack *stack)
{
	if (stack->count <= 100)
		stack->divisor = stack->count / 7;
	if (stack->count > 100)
		stack->divisor = stack->count / 4;
}



void	selective_pb(m_stack *st, int current, int previous)
{
	if (st->a->number < current && st->a->number >= previous)
	{
		pb(&st->a, &st->b, 1);
		if (st->b->number > current)
			rb(&st->b, 1);
	}
	else
		ra(&st->a, 1);
}

int	calculate_new_divisor(int size, m_stack *stack)
{
	if (size >= 250 && size <= 350)
		stack->divisor = 6;
	else if (size > 100)
		stack->divisor = 5;
	if (size <= 100)
		stack->divisor = 3;
	return (stack->divisor);
}

void	stack_b(m_stack *st)
{
	int	size;
	int	end;
	int	start;

	size = st->count;
	end = size / st->divisor;
	start = 0;
	while (st->a && ft_lstsize(st->a) > 5)
	{
		if (st->a && st->a->number < end && st->a->number < size - 5)
			selective_pb(st, end, start);
		else
			ra(&st->a, 1);
		if (ft_lstsize(st->b) == start)
		{
			st->divisor = calculate_new_divisor(ft_lstsize(st->a), st);
			start = end;
			end += ft_lstsize(st->a) / st->divisor;
		}
	}
}
