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


// this another algo that is going to be usefull in the future or not , this project if fuckign annoying.

void ft_sort_int_tab(int *tab, int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (tab[i] > tab[j])
            {
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
            j++;
        }
        i++;
    }
}


int choose_pivot(t_stack *a, int size)
{
    int i;
    int pivot;
    int *array;

    array = malloc(sizeof(int) * size);
    i = 0;
    while (i < size)
    {
        array[i] = a->number;
        a = a->next;
        i++;
    }
    ft_sort_int_tab(array, size);
    pivot = array[size / 2];
    free(array);
    return (pivot);
}

void quicksort_stack(t_stack **a, t_stack **b, int size)
{
    int pivot;
    int i;
    int smaller_elements = 0;

    if (is_sorted(*a) || size < 2)
        return;

    pivot = choose_pivot(*a, size);

    for (i = 0; i < size; i++)
    {
        if ((*a)->number < pivot)
        {
            pb(a, b);
            smaller_elements++;
        }
        else
            ra(a);
    }

    quicksort_stack(a, b, size - smaller_elements);
    while (smaller_elements--)
        pa(a, b);
    quicksort_stack(a, b, smaller_elements);
}


// this one might be usefull for smaller number of elemtents like 2 to 4 and thats it

void	ft_sort_small(t_stack **a)
{
    int last_operation = 0; // 0: none, 1: sa, 2: ra
    while (!is_sorted(*a))
    {
        if ((*a)->number > (*a)->next->number && last_operation != 2)
        {
            sa(a);
            last_operation = 1;
        }
        else if ((*a)->number > max_value(*a))
        {
            rra(a);
            last_operation = 0;
        }
        else if (last_operation != 1)
        {
            ra(a);
            last_operation = 2;
        }
    }
}

