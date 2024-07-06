/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:31:15 by ysemlali          #+#    #+#             */
/*   Updated: 2024/07/06 21:55:06 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	selective_pb(t_sort *st, int current, int previous)
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

void	update_threshold(t_sort *stack)
{
	int	size;

	size = ft_lstsize(stack->a);
	stack->begin = stack->end;
	if (size >= 350 && size < 500)
		stack->end += ft_lstsize(stack->a) / 8;
	else if (size >= 250 && size < 350)
		stack->end += ft_lstsize(stack->a) / 6;
	else if (size > 100 && size < 250)
		stack->end += ft_lstsize(stack->a) / 4;
	else if (size > 100)
		stack->end += ft_lstsize(stack->a) / 5;
	if (size <= 100)
		stack->end += ft_lstsize(stack->a) / 3;
	if (stack->end <= stack->begin)
		stack->end = stack->count;
}

void	selective_push(t_sort *stack)
{
	pb(&stack->a, &stack->b, 1);
	if (!(stack->b) || !(stack->b->next))
		return ;
	if (stack->b->number > (stack->begin / 2) + (stack->end / 2))
		rb(&stack->b, 1);
}

void	stack_b(t_sort *s, int div)
{
	int	n;

	s->begin = 0;
	s->end = s->count / div;
	while (s->a)
	{
		n = s->a->number;
		if (n <= s->end)
			selective_push(s);
		else
			ra(&s->a, 1);
		if (s->end == ft_lstsize(s->b))
			update_threshold(s);
	}
}
