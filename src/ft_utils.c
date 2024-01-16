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

t_stack *ft_get_stack(int ac, char **av)
{
    t_stack *a;
    t_stack *tmp;
    int i;

    i = 1;
    // printf("av[i] atoi: %d\n", ft_atoi(av[i]));
    // a = ft_lstnew(ft_atoi(av[i]));
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
    if (!(*a)->next)
        return ;
    if ((*a)->number > (*a)->next->number)
        sa(*a);
}

void ft_sort_three(t_stack **a)
{
    int one = (*a)->number;
    int two = (*a)->next->number;
    int three = (*a)->next->next->number;

    if (one > two && two > three && one > three)
    {
        sa(*a);
        rra(*a);
    }
    if (one < two && two > three && one < three)
    {
        sa(*a);
        ra(*a);
    }
    if (one > two && two < three && one < three)
        sa(*a);
    if (one > two && one > three && two < three)
        ra(*a);
    if (one < two && two > three && one > three)
        rra(*a);
}

void ft_sort_four(t_stack **a , t_stack **b)
{

    t_stack *tmp;
    tmp = *a;
    int i = 0;
    while (tmp->next)
    {
        if (tmp->number > tmp->next->number)
            ra(*a);
        tmp = tmp->next;
        i++;
    }
    pb(a, b);
    i = 0;
    while (*a)
    {
        i++;
        *a = (*a)->next;
    }
    printf("i: %d\n", i);
    ft_sort_three(a);
    pa(*a, *b);
}

void ft_push_swap(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    // b = NULL;
    a = ft_get_stack(ac, av);
    // t_stack *tmp = a;
    // (void)av;
    ac--;
    if (is_sorted(a))
        return ;
    if (ac  == 2)
        ft_sort_two(&a);
    if (ac == 3)
        ft_sort_three(&a);
    if (ac == 4)
        ft_sort_four(&a , &b);
    // if (ac > 6)
        // sort_big_stack(&a );
    // while(a)
    // {
    //     printf("a->number: %d\n", a->number);
    //     a = a->next;
    // }
}