/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:59:48 by ysemlali          #+#    #+#             */
/*   Updated: 2024/06/26 18:34:36 by codespace        ###   ########.fr       */
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


void	ft_index_stack(m_stack *stack)
{
	t_stack	*tmp;
	int		i;
	int		*array;
	int		size;

	i = 0;
	size = stack->count;
	array = malloc(sizeof(int) * size + 1);
	if (!array)
		return ;
	ft_fill_array(stack->a, array);
	ft_quick_sort(array, size);
	tmp = stack->a;
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

void	ft_sort_big(m_stack *stack)
{

	getdivisor(stack);
	ft_index_stack(stack);
	stack_b(stack);
	ft_sort_five(stack);
	stack_a(stack);



	t_stack *tmp = stack->a;
	while (tmp)
	{
		printf("%d\n", tmp->number);
		tmp = tmp->next;
	}
}
