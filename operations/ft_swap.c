/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:26:35 by ysemlali          #+#    #+#             */
/*   Updated: 2024/01/16 17:09:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void	sa(t_stack *a)
{
	int	tmp;

	if (a && a->next)
	{
		tmp = a->number;
		a->number = a->next->number;
		a->next->number = tmp;
	}
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	tmp;

	if (b && b->next)
	{
		tmp = b->number;
		b->number = b->next->number;
		b->next->number = tmp;
	}
	write(1, "sb\n", 3);
}

void	ss(t_stack *a , t_stack *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}
