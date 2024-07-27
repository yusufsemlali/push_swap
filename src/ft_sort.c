/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:59:44 by ysemlali          #+#    #+#             */
/*   Updated: 2024/07/26 22:11:27 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_swap(t_sort *stack)
{
	stack->a = ft_get_stack(stack->count, stack->values);
	if (is_sorted(stack->a) == 1)
	{
		free_all(stack);
		return ;
	}
	stack->b = NULL;
	if (stack->count == 2)
	{
		if (stack->a->number > stack->a->next->number)
			ra(&stack->a, 1);
	}
	else if (stack->count == 3)
		ft_sort_three(stack);
	else if (stack->count == 5 || stack->count == 4)
		ft_sort_small(stack);
	else if (stack->count > 5)
		ft_sort_big(stack);
	free_all(stack);
}
