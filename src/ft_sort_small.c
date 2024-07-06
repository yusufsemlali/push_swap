/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:00:00 by ysemlali          #+#    #+#             */
/*   Updated: 2024/07/06 21:48:13 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_three(t_sort *stack)
{
	int	max;

	max = ft_find_max(stack->a);
	if (stack->a->number == max)
		ra(&stack->a, 1);
	else if (stack->a->next->number == max)
		rra(&stack->a, 1);
	if (stack->a->number > stack->a->next->number)
		sa(&stack->a, 1);
}

void	ft_sort_small(t_sort *stack)
{
	int	i;

	i = 0;
	while (i < stack->count - 3)
	{
		push_smallest(stack);
		pb(&stack->a, &stack->b, 1);
		i++;
	}
	ft_sort_three(stack);
	while (stack->b)
		pa(&stack->a, &stack->b, 1);
}
