#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

int main(void)
{
    t_stack *a;
    t_stack *b;
    int i;

    i = 1;
    a = NULL;
    while (i <= 4)
    {
        ft_lstadd_back(&a, ft_lstnew(i));
        i++;
    }
    b = NULL;
    // pb(&a, &b);
    // pb(&a, &b);
    // pb(&a, &b);
    // pb(&a, &b);
    rra(&a);
    while (a)
    {
        printf("a: %d\n", a->number);
        a = a->next;
    }

    while (b)
    {
        printf("b: %d\n", b->number);
        b = b->next;
    }
}

// void ft_sort_five(t_stack **a, t_stack **b)
// {
//     int i = index_of_smallest(*a);
//     int x = 0;
//     t_stack *tmp = *a;
//     while (tmp->next)
//     {
//         tmp = tmp->next;
//         x++;
//     } 
//     if (x == i)
//         rra(a);
//     pb(a, b);
//     pb(a, b);
//     if ((*b)->number > (*b)->next->number)
//         rb(a);
//     ft_sort_three(a);
//     pa(a, b);
//     ft_sort_four(a, b);
//     pa(a, b);
// }


void	ft_sort_small(t_stack **a)
{
    t_stack *tmp = *a;
    while (tmp->next)
        tmp = tmp->next;
    if (tmp->number == min_value(*a))
        rra(a);
    while (!is_sorted(*a))
    {
        if ((*a)->number > (*a)->next->number && (*a)->next->number != min_value(*a))
            sa(a);
        else if ((*a)->number == max_value(*a))
            rra(a);
        else if ((*a)->number != min_value(*a) || ((*a)->number == min_value(*a) && (*a)->next->number != second_min_value(*a)))
            ra(a);
        else
            rra(a);
    }
}