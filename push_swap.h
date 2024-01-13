/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:20:27 by ysemlali          #+#    #+#             */
/*   Updated: 2024/01/13 00:37:12 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

// Define the structure for a stack node
typedef struct s_stack
{
	int				number;
	struct s_stack	*next;

}					t_stack;

// Function prototypes
// -- swap functions --
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
// -- push functions --
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
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
#endif