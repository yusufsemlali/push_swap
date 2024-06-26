/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:56:26 by ysemlali          #+#    #+#             */
/*   Updated: 2024/06/26 17:50:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

void	ft_sort_small(m_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->a->number;
	b = stack->a->next->number;
	c = stack->a->next->next->number;
	if (a < b && b < c)
		return ;
	if (a > b && a > c && b < c)
		ra(&stack->a, 1);
	if (a > b && a > c && b > c)
	{
		ra(&stack->a, 1);
		sa(&stack->a, 1);
	}
	if (a < b && b > c && a > c)
		rra(&stack->a, 1);
	if (a < b && b > c && a < c)
	{
		sa(&stack->a, 1);
		ra(&stack->a, 1);
	}
	if (a < c && b < c && a > b)
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
