/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:11:28 by codespace         #+#    #+#             */
/*   Updated: 2024/06/24 14:32:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_isvalid(int c, char c_next, m_stack *stack)
{
	if (c >= '0' && c <= '9' && (c_next == '-' || c_next == '+'))
		stack->error = 1;
	else if (c < '0' || c > '9')
	{
		if (c != ' ' && c != '-' && c != '+' && c != '\0')
			stack->error = 1;
		else if ((c == '-' || c == '+') && (c_next < '0' || c_next > '9'
				|| c_next == '\0'))
			stack->error = 1;
	}
}

int	ft_get_count(char **values)
{
	int	i;

	i = 0;
	while (values[i] != NULL)
		i++;
	return (i);
}

m_stack	*ft_stack(int ac, char **av)
{
	m_stack	*stack;
	int		i;
	int		x;
	char	*temp;

	i = 1;
	stack = ft_calloc(1, sizeof(m_stack));
	while (i < ac)
	{
		x = 0;
		while (av[i][x])
		{
			if (av[i][x] == '\n')
				av[i][x] = ' ';
			ft_isvalid(av[i][x], av[i][x + 1], stack);
			x++;
		}
		temp = ft_strjoin(stack->av, " ");
		stack->av = ft_strjoin(temp, av[i]);
		i++;
	}
	stack->values = ft_split(stack->av, ' ');
	stack->count = ft_get_count(stack->values);
	return (stack);
}

int	ft_check_doubles(m_stack *stack)
{
	int		i;
	int		j;
	long	val;

	i = 0;
	while (i < stack->count)
	{
		val = ft_atoi(stack->values[i]);
		if (val > INT_MAX || val < INT_MIN)
			return (stack->error = 1, 0);
		j = i + 1;
		while (j < stack->count)
		{
			if (val == ft_atoi(stack->values[j]))
				return (stack->error = 1, 0);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	m_stack	*stack;

	if (ac < 2)
		return (0);
	stack = ft_stack(ac, av);
	if (stack->count == 1)
		return 0;
	ft_check_doubles(stack);
	if (stack->error == 1)
	{
		write(1, "Error\n", 6);
		free_all(stack);
		return (0);
	}
	ft_push_swap(stack);
	return (0);
}
