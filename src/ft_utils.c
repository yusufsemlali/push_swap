#include "../push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>

int is_sorted(t_stack *a)
{
    t_stack *tmp;
    
    tmp = a;
    while(tmp->next)
    {
        if (tmp->number > tmp->next->number)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int index_of_smallest(t_stack *a)
{
    int i = 0;
    int index = 0;
    int min = a->number;

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

int min_value(t_stack *a)
{
    int min = a->number;
    while (a)
    {
        if (a->number < min)
            min = a->number;
        a = a->next;
    }
    return min;
}

int second_min_value(t_stack *a)
{
    int min = min_value(a);
    int second_min = INT_MAX;

    while (a)
    {
        if (a->number < second_min && a->number != min)
            second_min = a->number;
        a = a->next;
    }
    return second_min;
}

int max_value(t_stack *a)
{
    int max = a->number;
    while (a)
    {
        if (a->number > max)
            max = a->number;
        a = a->next;
    }
    return max;
}

t_stack *ft_get_stack(int ac, char **av)
{
    t_stack *a;
    t_stack *tmp;
    int i;

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
void ft_sort_two(t_stack **a)
{
    if (*a)
    {
        if ((*a)->number > (*a)->next->number)
            sa(a);
    }
}

void ft_sort_three(t_stack **a)
{
    int one = (*a)->number;
    int two = (*a)->next->number;
    int three = (*a)->next->next->number;

    if (one > two && two > three && one > three)
    {
        sa(a);
        rra(a);
    }
    if (one < two && two > three && one < three)
    {
        sa(a);
        ra(a);
    }
    if (one > two && two < three && one < three)
        sa(a);
    if (one > two && one > three && two < three)
        ra(a);
    if (one < two && two > three && one > three)
        rra(a);
}


void ft_sort_four(t_stack **a , t_stack **b)
{
    int i = index_of_smallest(*a);
    while (i--)
        ra(a);
    pb(a, b);
    ft_sort_three(a);
    pa(a, b);
}

// void	ft_sort_small(t_stack **a)
// {
//     int last_operation = 0; // 0: none, 1: sa, 2: ra
//     while (!is_sorted(*a))
//     {
//         if ((*a)->number > (*a)->next->number && last_operation != 2)
//         {
//             sa(a);
//             last_operation = 1;
//         }
//         else if ((*a)->number > max_value(*a))
//         {
//             rra(a);
//             last_operation = 0;
//         }
//         else if (last_operation != 1)
//         {
//             ra(a);
//             last_operation = 2;
//         }
//     }
// }

// void	ft_sort_small(t_stack **a, t_stack **b)
// {
//     while (*a)
//     {
//         while ((*a)->number != min_value(*a))
//             ra(a);
//         pb(a, b);
//     }
//     while (*b)
//         pa(a, b);
// }
void	ft_sort_small(t_stack **a, t_stack **b)
{
    while (*a)
    {
        while ((*a)->number != min_value(*a))
            ra(a);
        pb(a, b);
    }
    while (*b)
        pa(a, b);
}

void ft_sort_five(t_stack **a, t_stack **b)
{
    // Push the two smallest numbers to stack b
    for (int i = 0; i < 2; ++i)
    {
        int min_index = index_of_smallest(*a);
        while (min_index--)
            ra(a);
        pb(a, b);
    }

    // Sort the remaining three numbers in stack a
    ft_sort_three(a);
    pa(a, b);
    pa(a, b);
}

void ft_push_swap(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    a = ft_get_stack(ac, av);
    ac--;
    if (is_sorted(a))
        return ;
    if (ac > 1 && ac < 5)
        ft_sort_small(&a , &b);
    else if (ac == 5)
        ft_sort_five(&a, &b);
    // else if (ac > 5)
        // ft_sort(&a, &b);

    // while(a)
    // {
    //     printf("a->number: %d\n", a->number);
    //     a = a->next;
    // }




}