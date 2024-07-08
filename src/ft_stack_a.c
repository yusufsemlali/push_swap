/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:31:54 by ysemlali          #+#    #+#             */
/*   Updated: 2024/07/08 09:01:38 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	calculate_low_cost(t_sort *s)
{
	t_stack	*tmp;
	int		i;
	int		size;

	if (s->i == -1 || !s->b)
		return (-2);
	tmp = s->b;
	i = 0;
	size = ft_lstsize(s->b);
	while (tmp && tmp->number != s->i)
	{
		i++;
		tmp = tmp->next;
	}
	if (!tmp)
		return (-2);
	if (i < size / 2)
		return (1);
	else
		return (-1);
}

void	max_to_top(t_sort *stack)
{
	int	cost;

	stack->i = ft_find_max(stack->b);
	if (stack->i == -1)
		return ;
	if (stack->b->number == stack->i)
		return ;
	if (stack->b->next->number == stack->i)
	{
		sb(&stack->b, 1);
		return ;
	}
	cost = calculate_low_cost(stack);
	if (cost == 1)
		rb(&stack->b, 1);
	else if (cost == -1)
		rrb(&stack->b, 1);
	else
		return ;
}

void	stack_a(t_sort *stack)
{
	while (stack->b)
	{
		max_to_top(stack);
		if (stack->b->number == stack->i || stack->b->number == stack->i - 1)
		{
			pa(&stack->a, &stack->b, 1);
			if (stack->a && stack->a->next
				&& (stack->a->number > stack->a->next->number))
				sa(&stack->a, 1);
		}
	}
}
