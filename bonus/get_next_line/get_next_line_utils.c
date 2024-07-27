/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:02:33 by ysemlali          #+#    #+#             */
/*   Updated: 2024/07/26 19:36:44 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ln_index(char *buf)
{
	size_t	i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i] && buf[i] != '\n')
		i++;
	return (i);
}

size_t	ft_strsize(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t	catnate(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_d;
	size_t	len_s;

	i = 0;
	if (!dst && src && !dstsize)
		return (ft_strsize(src));
	len_d = ft_strsize(dst);
	len_s = ft_strsize(src);
	if (dstsize == 0 || len_d >= dstsize)
		return (dstsize + len_s);
	while (src[i] && i < (dstsize - 1 - len_d))
	{
		dst[len_d + i] = src[i];
		i++;
	}
	dst[len_d + i] = '\0';
	return (len_d + len_s);
}

char	*strsub(char *s, unsigned int start, size_t len)
{
	char	*str;
	char	*str_start;

	if (!s || start >= ft_strsize(s))
		return (NULL);
	if (len > ft_strsize(s) - start)
		len = ft_strsize(s) - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str_start = str;
	s += start;
	while (len--)
		*str++ = *s++;
	*str = '\0';
	return (str_start);
}

char	*ft_strjoin(char *line, char *buf)
{
	char	*concat;

	if (!line && !buf)
		return (NULL);
	concat = (char *)malloc(ft_strsize(line) + ft_strsize(buf) + 1);
	if (!concat)
		return (NULL);
	concat[0] = '\0';
	if (line)
		catnate(concat, line, ft_strsize(line) + 1);
	catnate(concat, buf, ft_strsize(buf) + ft_strsize(line) + 1);
	if (!concat[0])
		return (free(concat), NULL);
	return (free(line), concat);
}
