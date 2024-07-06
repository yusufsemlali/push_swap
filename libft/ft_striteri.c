/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:46:31 by ysemlali          #+#    #+#             */
/*   Updated: 2024/07/06 21:28:41 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;
	int	size;

	size = ft_strlen(s);
	if (!s || !f)
		return ;
	i = 0;
	while (i < size)
	{
		f(i, &s[i]);
		i++;
	}
}
