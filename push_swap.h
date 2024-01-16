/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:20:27 by ysemlali          #+#    #+#             */
/*   Updated: 2024/01/16 20:53:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
#include "libft/libft.h"

// Function prototypes
// -- swap functions --
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
// -- push functions --
void				pa(t_stack *a, t_stack *b);
void	            pb(t_stack **a, t_stack **b);
// -- rotate functions --
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
// -- reverse rotate functions --
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
// -- operations --
void				ft_swap(t_stack **stack);
void				ft_push(t_stack **stack1, t_stack **stack2);
void				ft_rotate(t_stack **stack);
void				ft_reverse_rotate(t_stack **stack);
// -- util functions --
void ft_push_swap(int ac, char **av);
// t_stack ft_get_stack(int ac, char **av);
// void ft_sort_two(t_stack **a);
// void ft_sort_three(t_stack **a);
// void ft_sort_four(t_stack **a, t_stack **b);
// void ft_sort_five(t_stack **a, t_stack **b);
// void ft_sort(t_stack **a, t_stack **b);
#endif