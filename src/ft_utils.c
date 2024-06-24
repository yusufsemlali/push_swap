/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:55:03 by ysemlali          #+#    #+#             */
/*   Updated: 2024/06/09 11:17:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"


void	free_all(m_stack *stack)
{
	int	i;

	i = 0;
	while (stack->values[i] != NULL)
	{
		free(stack->values[i]);
		i++;
	}
	free(stack->values);
	free(stack->av);
	free(stack);
}

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

	tmp = a;
	while (tmp->next)
	{
		if (tmp->number > tmp->next->number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_find_min(t_stack *a)
{
	t_stack	*tmp;
	int		min;
	int		min_index;
	int		i;

	i = 0;
	min = a->number;
	min_index = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->number < min)
		{
			min = tmp->number;
			min_index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_index);
}

void	push_smallest(t_stack **a, int smallest)
{
	int	size;
	int	mid;

	size = ft_lstsize(*a);
	mid = size / 2;
	if (smallest <= mid)
		while (smallest-- > 0)
			ra(a, 1);
	else
		while (size-- > smallest)
			rra(a, 1);
}
