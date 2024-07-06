/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:55:03 by ysemlali          #+#    #+#             */
/*   Updated: 2024/07/06 21:47:57 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_get_stack(int count, char **values)
{
	t_stack	*a;
	t_stack	*tmp;
	int		i;

	i = 0;
	a = NULL;
	while (i < count)
	{
		tmp = ft_lstnew(ft_atoi(values[i]));
		ft_lstadd_back(&a, tmp);
		i++;
	}
	return (a);
}

int	is_sorted(t_stack *a)
{
	t_stack	*tmp;

	if (!a)
		return (0);
	tmp = a;
	if (!tmp)
		return (0);
	while (tmp->next)
	{
		if (tmp->number > tmp->next->number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_find_min(t_stack *s)
{
	int		min;
	t_stack	*tmp;

	tmp = s;
	min = s->number;
	while (tmp)
	{
		if (tmp->number < min)
			min = tmp->number;
		tmp = tmp->next;
	}
	return (min);
}

int	ft_find_max(t_stack *s)
{
	int		max;
	t_stack	*tmp;

	if (!s)
		return (0);
	max = s->number;
	tmp = s;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if (tmp->number > max)
			max = tmp->number;
		tmp = tmp->next;
	}
	return (max);
}

void	push_smallest(t_sort *s)
{
	int		min;
	t_stack	*tmp;

	s->i = 0;
	tmp = s->a;
	min = ft_find_min(s->a);
	while (tmp)
	{
		if (tmp->number == min)
			break ;
		s->i++;
		tmp = tmp->next;
	}
	if (s->i < s->count / 2)
		while (s->a->number != min)
			ra(&s->a, 1);
	else
		while (s->a->number != min)
			rra(&s->a, 1);
}
