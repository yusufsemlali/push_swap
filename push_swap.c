/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:48:43 by ysemlali          #+#    #+#             */
/*   Updated: 2024/07/08 09:01:15 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_sort	*stack;

	if (ac == 1)
		return (0);
	stack = ft_stack(ac, av);
	if (stack->error == 1)
	{
		free_all(stack);
		return (0);
	}
	ft_check_doubles(stack);
	if (stack->error == 1)
	{
		free_all(stack);
		return (0);
	}
	ft_push_swap(stack);
	return (0);
}
