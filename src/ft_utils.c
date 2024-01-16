#include "../push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>

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

void sort_small_stack(t_stack **a)
{
    if (!(*a)->next)
        return ;
    if ((*a)->number > (*a)->next->number)
        sa(*a);
    if ((*a)->next->number > (*a)->next->next->number)
        rra(*a);
    if ((*a)->number > (*a)->next->number)
        sa(*a);
}

void ft_push_swap(int ac, char **av)
{
    t_stack *a;
    // t_stack *b;

    a = NULL;
    a = ft_get_stack(ac, av);
    // t_stack *tmp = a;
    // b = NULL;
    // (void)av;
    ac--;
    if (ac  == 2)
        ft_sort_two(&a);
    // if (ac >= 3 && ac <= 6)
        // sort_small_stack(&a);
    // if (ac > 6)
        // sort_big_stack(&a);
    // while (tmp)
    // {
    //     printf("%d\n", tmp->number);
    //     tmp = tmp->next;
    // }
}