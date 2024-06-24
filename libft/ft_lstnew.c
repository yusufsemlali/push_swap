/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:00:56 by ysemlali          #+#    #+#             */
/*   Updated: 2024/06/08 14:34:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstnew(int number)
{
	t_stack	*result;

	result = malloc(sizeof(t_stack));
	if (!result)
		return (NULL);
	result->number = number;
	result->next = NULL;
	return (result);
}
