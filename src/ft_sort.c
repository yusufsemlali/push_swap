/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:51:50 by ysemlali          #+#    #+#             */
/*   Updated: 2024/06/24 14:26:32by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"
#include <stdio.h>

void	ft_push_swap(m_stack *stack)
{

	stack->a = ft_get_stack(stack->count, stack->values);
	stack->b = NULL;
	if (stack->count == 2)
	{
		if (stack->a->number > stack->a->next->number)
			ra(&stack->a, 1);
	}
	else if(stack->count == 3)
		ft_sort_small(stack);
	else if (stack->count == 4)
		ft_sort_four(stack);
	else if (stack->count == 5)
		ft_sort_five(stack);
	else if (stack->count > 5)	
		ft_sort_big(stack);
	
}



