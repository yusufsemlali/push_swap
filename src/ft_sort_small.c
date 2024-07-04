/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemlali <ksemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:56:26 by ysemlali          #+#    #+#             */
/*   Updated: 2024/07/04 08:02:18 by ksemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

int get_max(t_stack *s)
{
	int max;
	max = s->number;
	while (s)
	{
		if (s->number > max)
			max = s->number;
		s = s->next;
	}
	return (max);
}


void	ft_sort_small(m_stack *stack)
{
	int max = get_max(stack->a);
	if (stack->a->number == max)
		ra(&stack->a, 1);
	else if (stack->a->next->number == max)
		rra(&stack->a, 1);
	if (stack->a->number > stack->a->next->number)
		sa(&stack->a, 1);
}

void	ft_sort_four(m_stack *stack)
{
	int	min;

	min = ft_find_min(stack->a);
	if (min == 3)
		rra(&stack->a, 1);
	else
		while (min-- > 0)
			ra(&stack->a, 1);
	if (is_sorted(stack->a))
		return ;
	pb(&stack->a, &stack->b, 1);
	ft_sort_small(stack);
	pa(&stack->a, &stack->b, 1);
}

void	ft_sort_five(m_stack *stack)
{
	int	smallest;
	int	i;

	i = 0;
	while (i < 2)
	{
		smallest = ft_find_min(stack->a);
		push_smallest(&stack->a, smallest);
		pb(&stack->a, &stack->b, 1);
		i++;
	}
	ft_sort_small(stack);
	pa(&stack->a, &stack->b, 1);
	pa(&stack->a, &stack->b, 1);
}
