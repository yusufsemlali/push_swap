/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:51:50 by ysemlali          #+#    #+#             */
/*   Updated: 2024/06/09 13:30:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"
#include <stdio.h>

void	ft_push_swap(int count, char **values)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	(void)b;
	a = ft_get_stack(count, values);
	// t_stack tmp = *a;
	while (a != NULL)
	{
		printf("a->number = %d\n", a->number);
		a = a->next;
	}
	// while (tmp != NULL)
	// {
	// 	free(tmp);
	// 	tmp = tmp->next;
	// }
}