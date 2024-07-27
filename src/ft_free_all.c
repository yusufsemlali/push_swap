/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:56:16 by ysemlali          #+#    #+#             */
/*   Updated: 2024/07/26 19:56:42 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	del_int(int number)
{
	(void)number;
}

void	free_all(t_sort *stack)
{
	int	i;

	if (stack->error == 1)
		write(1, "Error\n", 6);
	if (stack)
	{
		ft_lstclear(&stack->a, del_int);
		ft_lstclear(&stack->b, del_int);
		if (stack->av)
			free(stack->av);
		if (stack->values)
		{
			i = 0;
			while (stack->values[i] != NULL)
			{
				free(stack->values[i]);
				i++;
			}
			free(stack->values);
		}
		free(stack);
	}
}
