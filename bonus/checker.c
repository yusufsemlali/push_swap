/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:38:34 by ysemlali          #+#    #+#             */
/*   Updated: 2024/07/26 22:11:01 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line/get_next_line.h"

void	error_exit(char *line)
{
	if (line)
	{
		write(1, "Error\n", 6);
		free(line);
	}
}

void	ft_bonus_check(t_sort *bonus)
{
	char	*line;

	bonus->a = ft_get_stack(bonus->count, bonus->values);
	line = get_next_line(0);
	while (line)
	{
		if (ft_strchr(line, 's'))
			swap_check(line, bonus);
		else if (ft_strchr(line, 'p'))
			push_check(line, bonus);
		else if (ft_strchr(line, 'r'))
			rotate_check(line, bonus);
		else
		{
			error_exit(line);
			return ;
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (is_sorted(bonus->a) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_sort	*bonus;

	if (ac == 1)
		return (0);
	bonus = ft_stack(ac, av);
	if (bonus->error == 1)
	{
		free_all(bonus);
		return (0);
	}
	ft_check_doubles(bonus);
	if (bonus->error == 1)
	{
		free_all(bonus);
		return (0);
	}
	ft_bonus_check(bonus);
	free_all(bonus);
}
