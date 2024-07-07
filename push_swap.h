/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemlali <ksemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:20:27 by ysemlali          #+#    #+#             */
/*   Updated: 2024/07/07 18:41:58 by ksemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct p_s_meta_data
{
	t_stack	*a;
	t_stack	*b;
	char	*av;
	char	**values;
	int		count;
	int		error;
	int		div;
	int		max;
	int		begin;
	int		end;
	int		i;
}			t_sort;

// Function prototypes
// -- swap functions --
void		sa(t_stack **a, int p);
void		sb(t_stack **b, int p);
void		ss(t_stack **a, t_stack **b);
// -- push functions --
void		pa(t_stack **a, t_stack **b, int p);
void		pb(t_stack **a, t_stack **b, int p);
void		pb(t_stack **a, t_stack **b, int p);
// -- rotate functions --
void		ra(t_stack **a, int p);
void		rb(t_stack **b, int p);
void		rr(t_stack **a, t_stack **b);
// -- reverse rotate functions --
void		rra(t_stack **a, int p);
void		rrb(t_stack **b, int p);
void		rrr(t_stack **a, t_stack **b);
// -- parsing functions --
t_sort		*ft_stack(int ac, char **av);
int			ft_check_doubles(t_sort *stack);

// -- sort functions --
void		ft_push_swap(t_sort *stack);
void		ft_sort_three(t_sort *stack);
void		ft_sort_small(t_sort *stack);
void		ft_sort_big(t_sort *stack);
// -- utils functions --
t_stack		*ft_get_stack(int ac, char **av);
int			is_sorted(t_stack *a);
int			ft_find_min(t_stack *a);
int			ft_find_max(t_stack *s);
void		push_smallest(t_sort *stack);
void		stack_b(t_sort *stack, int div);
void		stack_a(t_sort *stack);
void		free_all(t_sort *stack);

#endif
