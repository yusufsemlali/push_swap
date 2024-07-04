/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemlali <ksemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:08:32 by codespace         #+#    #+#             */
/*   Updated: 2024/07/01 15:28:34 by ksemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../push_swap.h"

// int calculate_new_divisor(int size)
// {
//     int divisor;

//     if (size <= 100)
//         divisor = size / 7;
//     else
//         divisor = size / 4;
//     return (divisor);
// }

// void stack_a(m_stack *st)
// {
//     int size;
//     int divisor;


//     size = ft_lstsize(st->b) - 1;
//     while (st->b)
//     {
//         while ((st->b) && (st->b->number == size || st->b->number == size -1))
//         {
//             pa(&st->a, &st->b, 1);
//             if (st->a->number == size)
//                 size = ft_lstsize(st->b) - 1;
//             if (st->a && st->a->next && st->a->number > st->a->next->number)
//                 sa(&st->a, 1);
//         }
//         if (st->b && st->b->next && st->b->next->number == size)
//             sb(&st->b, 1);
//         else
//         {
//             divisor = calculate_new_divisor(ft_lstsize(st->b));
//             if (divisor < size / 2)
//                 rb(&st->b, 1);
//             else
//                 rrb(&st->b, 1);
//         }
//     }
// }