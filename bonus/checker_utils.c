/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:25:59 by ysemlali          #+#    #+#             */
/*   Updated: 2024/07/26 23:02:32 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line/get_next_line.h"

void	swap_check(char *line, t_sort *bonus)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(&bonus->a, 0);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(&bonus->b, 0);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(&bonus->a, &bonus->b, 0);
}

void	push_check(char *line, t_sort *bonus)
{
	if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(&bonus->a, &bonus->b, 0);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(&bonus->a, &bonus->b, 0);
}

void	rotate_check(char *line, t_sort *bonus)
{
	if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(&bonus->a, 0);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(&bonus->b, 0);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(&bonus->a, &bonus->b, 0);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(&bonus->a, 0);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(&bonus->b, 0);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(&bonus->a, &bonus->b, 0);
}
