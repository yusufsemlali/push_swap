/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:24:31 by ysemlali          #+#    #+#             */
/*   Updated: 2024/07/08 09:02:12 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_isvalid(int c, char c_next, t_sort *stack)
{
	if (!ft_isdigit(c) && c != ' ' && c != '-' && c != '+' && c != '\0')
		stack->error = 1;
	if (ft_isdigit(c) && (c_next == '-' || c_next == '+'))
		stack->error = 1;
	if ((c == '-' && c_next == ' ') || (c == '+' && c_next == ' '))
		stack->error = 1;
	if ((c == '-' && c_next == '\0') || (c == '+' && c_next == '\0'))
		stack->error = 1;
	if ((c == '-' && c_next == '-') || (c == '+' && c_next == '+'))
		stack->error = 1;
	if (c == '-' && c_next == '+')
		stack->error = 1;
}

int	ft_get_count(char **values)
{
	int	i;

	i = 0;
	while (values[i] != NULL)
		i++;
	return (i);
}

void	ft_has_value(char *av, t_sort *stack)
{
	int	i;

	i = 0;
	while (av[i] == ' ')
		i++;
	if (av[i] == '\0')
		stack->error = 1;
}

int	ft_check_doubles(t_sort *stack)
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

t_sort	*ft_stack(int ac, char **av)
{
	t_sort	*stack;
	char	*temp;
	int		x;

	stack = ft_calloc(1, sizeof(t_sort));
	stack->i = 0;
	while (++stack->i < ac)
	{
		if (ft_strlen(av[stack->i]) == 0)
			stack->error = 1;
		x = 0;
		while (av[stack->i][x])
		{
			if (av[stack->i][x] == '\n')
				av[stack->i][x] = ' ';
			ft_has_value(av[stack->i], stack);
			ft_isvalid(av[stack->i][x], av[stack->i][x + 1], stack);
			x++;
		}
		temp = ft_strjoin(stack->av, " ");
		stack->av = ft_strjoin(temp, av[stack->i]);
	}
	stack->values = ft_split(stack->av, ' ');
	stack->count = ft_get_count(stack->values);
	return (stack);
}
