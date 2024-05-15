/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:59:48 by ysemlali          #+#    #+#             */
/*   Updated: 2024/05/14 20:48:40 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"
#include <stdio.h>

void	ft_fill_array(t_stack *a, int *array)
{
	int	i;

	i = 0;
	while (a)
	{
		array[i] = a->number;
		a = a->next;
		i++;
	}
}

void	ft_quick_sort(int arr[], int n)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	if (n < 2)
		return ;
	pivot = arr[n / 2];
	i = 0;
	j = n - 1;
	while (1)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i >= j)
			break ;
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	ft_quick_sort(arr, i);
	ft_quick_sort(arr + i, n - i);
}


void	ft_index_stack(t_stack *a)
{
	t_stack	*tmp;
	int		i;
	int		*array;
	int		size;

	i = 0;
	size = ft_lstsize(a);
	array = malloc(sizeof(int) * size + 1);
	if (!array)
		return ;
	ft_fill_array(a, array);
	ft_quick_sort(array, size);
	tmp = a;
	while (tmp && i < size)
	{
		if (tmp->number == array[i])
		{
			tmp->number = i;
			tmp = tmp->next;
			i = -1;
		}
		i++;
	}
	free(array);
}

void	ft_sort_big(t_stack **a, t_stack **b, int ac)
{
	// first we stack the index of the numbers in the stack
	ft_index_stack(*a);
	while (*a)
	{
		printf("%d\n", (*a)->number);
		*a = (*a)->next;
	}
	(void)b;
	(void)ac;
	// then we sort the stack
}