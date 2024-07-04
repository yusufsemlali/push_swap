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

int	get_threshold(int count)
{
	if (count <= 100)
		return (count / 4);
	if (count > 100)
		return (count / 7);
	return (0);
}

void	update_threshold(m_stack *stack)
{
	int	size;
	int	range;

	size = ft_lstsize(stack->a);
	printf("SIZE = %d\n", size);
	if (size > 100)
		range = size / 8;
	else
		range = size / 4;
	stack->begin = stack->end + 1;
	stack->end = stack->begin + range - 1;
	if (stack->end > stack->count)
		stack->end = stack->count;
	printf("END = %d \n BEGIN = %d\n", stack->end, stack->begin);
}

void	selective_push(m_stack *stack)
{
	pb(&stack->a, &stack->b, 1);
	if (!(stack->b) || !(stack->b->next))
		return ;
	if (stack->b->number < stack->b->next->number)
		sb(&stack->b, 1);
}

void	stack_b(m_stack *s)
{
	int	n;

	s->begin = 0;
	s->end = get_threshold(s->count);
	printf("END = %d \n BEGIN = %d\n", s->end , s->begin);
	exit(0);
	s->i = 0;
	while (s->a)
	{
		n = s->a->number;
		if (n >= s->begin && n <= s->end)
		{
			s->i++;
			selective_push(s);
		}
		else
		{
			printf("%d\n", n);
			sleep(1);
			ra(&s->a, 0);
		}
		if (s->i == s->end)
		{
			printf("s->i = %d\n", s->i);
			update_threshold(s);
		}
	}
}

