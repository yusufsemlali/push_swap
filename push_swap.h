/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:20:27 by ysemlali          #+#    #+#             */
/*   Updated: 2024/06/09 11:11:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct p_s_meta_data
{
	t_stack	*a;
	t_stack	*b;
	int 	i;
	char	*av;
	char	**values;
	int		count;
	int		n;
	int 	error;
}			m_stack;

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
// -- sort functions --
void		ft_push_swap(int ac, char **av);
void		ft_sort_small(t_stack **a);
void		ft_sort_four(t_stack **a, t_stack **b);
void		ft_sort_five(t_stack **a, t_stack **b);
void		ft_sort_big(t_stack **a, t_stack **b, int ac);
// -- utils functions --
t_stack		*ft_get_stack(int ac, char **av);
int			is_sorted(t_stack *a);
int			ft_find_min(t_stack *a);
void		push_smallest(t_stack **a, int smallest);
void	free_all(m_stack *stack);



#endif