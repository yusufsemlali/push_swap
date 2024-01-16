/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:28:36 by ysemlali          #+#    #+#             */
/*   Updated: 2024/01/16 20:54:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void	pa(t_stack **a, t_stack **b)
{
    t_stack	*tmp;

    if (*b)
    {
        tmp = (*b)->next;
        (*b)->next = *a;
        *a = *b;
        *b = tmp;
    }
    write(1, "pa\n", 3);
}

// void	pb(t_list **src, t_list **dst)
// {
// 	t_list	*new;
// 	t_list	*hel;

// 	hel = *src;
// 	if (src == NULL)
// 		return ;
// 	new = *src;
// 	*src = hel->next;
// 	new->next = *dst;
// 	*dst = new;
// 	write(1, "pb\n", 3);
// }

void	pb(t_stack **a, t_stack **b)
{
    t_stack	*tmp;

    if (*a)
    {
        tmp = (*a)->next;
        (*a)->next = *b;
        *b = *a;
        *a = tmp;
    }
    write(1, "pb\n", 3);
}
