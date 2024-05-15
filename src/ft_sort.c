/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:51:50 by ysemlali          #+#    #+#             */
/*   Updated: 2024/05/14 20:09:56 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"
#include <stdio.h>

void	ft_push_swap(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	a = ft_get_stack(ac, av);
	ac--;
	if (is_sorted(a))
		return ;
	if (ac > 1 && ac < 4)
		ft_sort_small(&a);
	else if (ac == 4)
		ft_sort_four(&a, &b);
	else if (ac == 5)
		ft_sort_five(&a, &b);
	else if (ac > 5 && ac < 101)
		ft_sort_big(&a, &b, ac);
}
