/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:25:59 by ysemlali          #+#    #+#             */
/*   Updated: 2024/07/26 21:39:27 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>

void	swap_check(char *line, t_sort *bonus)
{
	if (ft_strncmp(line, "sa", 2) == 0)
		sa(&bonus->a, 0);
	else if (ft_strncmp(line, "sb", 2) == 0)
		sb(&bonus->b, 0);
	else if (ft_strncmp(line, "ss", 2) == 0)
		ss(&bonus->a, &bonus->b, 0);
}

void	push_check(char *line, t_sort *bonus)
{
	if (ft_strncmp(line, "pa", 2) == 0)
		pa(&bonus->a, &bonus->b, 0);
	else if (ft_strncmp(line, "pb", 2) == 0)
		pb(&bonus->a, &bonus->b, 0);
}

void	rotate_check(char *line, t_sort *bonus)
{
	if (ft_strncmp(line, "rra", 3) == 0)
		rra(&bonus->a, 0);
	else if (ft_strncmp(line, "rrb", 3) == 0)
		rrb(&bonus->b, 0);
	else if (ft_strncmp(line, "rrr", 3) == 0)
		rrr(&bonus->a, &bonus->b, 0);
	else if (ft_strncmp(line, "ra", 2) == 0)
		ra(&bonus->a, 0);
	else if (ft_strncmp(line, "rb", 2) == 0)
		rb(&bonus->b, 0);
	else if (ft_strncmp(line, "rr", 2) == 0)
		rr(&bonus->a, &bonus->b, 0);
}
