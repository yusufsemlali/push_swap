#include "../libft/libft.h"
#include "../push_swap.h"
#include <stdio.h>

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

int	index_of_smallest(t_stack *a)
{
	int	i;
	int	index;
	int	min;

	i = 0;
	index = 0;
	min = a->number;
	while (a)
	{
		if (a->number < min)
		{
			min = a->number;
			index = i;
		}
		a = a->next;
		i++;
	}
	return (index);
}

int	min_value(t_stack *a)
{
	int	min;

	min = a->number;
	while (a)
	{
		if (a->number < min)
			min = a->number;
		a = a->next;
	}
	return (min);
}

int	second_min_value(t_stack *a)
{
	int	min;
	int	second_min;

	min = min_value(a);
	second_min = INT_MAX;
	while (a)
	{
		if (a->number < second_min && a->number != min)
			second_min = a->number;
		a = a->next;
	}
	return (second_min);
}

int	max_value(t_stack *a)
{
	int	max;

	max = a->number;
	while (a)
	{
		if (a->number > max)
			max = a->number;
		a = a->next;
	}
	return (max);
}

t_stack	*ft_get_stack(int ac, char **av)
{
	t_stack	*a;
	t_stack	*tmp;
	int		i;

	i = 1;
	a = NULL;
	while (i < ac)
	{
		tmp = ft_lstnew(ft_atoi(av[i]));
		ft_lstadd_back(&a, tmp);
		i++;
	}
	return (a);
}
void	ft_sort_small(t_stack **a)
{
    while (!is_sorted(*a))
    {
        if ((*a)->number > (*a)->next->number)
            sa(a);
        else
            rra(a);
    }
}

void	bring_min_to_front(t_stack **a, int ac)
{
    int	i = index_of_smallest(*a);
    int	x = 0;
    t_stack *tmp = *a;
    while (tmp->next)
    {
        tmp = tmp->next;
        x++;
    } 
    if (x == i)
        rra(a);
    else if (i == 0)
        return ;
    else if (i <= ac / 2)
        while (i--)
            ra(a);
    else
        while (i++ < ac)
            rra(a);
}

void	ft_sort_four(t_stack **a, t_stack **b, int ac)
{
	bring_min_to_front(a, ac);
	pb(a, b);
	ft_sort_small(a);
	pa(a, b);
}


void	ft_sort_five(t_stack **a, t_stack **b, int ac)
{
    bring_min_to_front(a, ac);
    pb(a, b);
    ft_sort_four(a, b, 4);
    pa(a, b);
}

void ft_sort_big(t_stack **a, t_stack **b, int ac)
{
	int i = 0;
	int min = min_value(*a);
	int max = max_value(*a);
	int second_min = second_min_value(*a);
	printf("min: %d\n", min);
	printf	("max: %d\n", max);
	printf("second_min: %d\n", second_min);
	(void)ac;
	while (i < ac)
	{
		min = min_value(*a);
		if ((*a)->number == min)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	// while (i < ac - 3)
	// {
	// 	if ((*a)->number == min || (*a)->number == max || (*a)->number == second_min)
	// 	{
	// 		pb(a, b);
	// 		i++;
	// 	}
	// 	else
	// 		ra(a);
	// }
	// ft_sort_small(a);
	while (i--)
		pa(a, b);

}


void	ft_push_swap(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	a = ft_get_stack(ac, av);
	ac--;
	if (is_sorted(a))
		return ;
	if (ac > 1 && ac < 4)
		ft_sort_small(&a);
    else if (ac == 4)
        ft_sort_four(&a, &b, 4);
	else if (ac == 5)
		ft_sort_five(&a, &b , ac);
	else if (ac > 5 && ac < 101)
		ft_sort_big(&a, &b, ac);
	// else if (ac > 5)
	// ft_sort(&a, &b);

	while(a)
	{
	    printf("a->number: %d\n", a->number);
	    a = a->next;
	}



}