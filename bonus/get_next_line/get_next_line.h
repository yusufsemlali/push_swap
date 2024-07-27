/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:08:11 by ysemlali          #+#    #+#             */
/*   Updated: 2024/07/26 22:11:07 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char	*get_next_line(int fd);
size_t	ft_strsize(char *str);
size_t	ln_exists(char *buf);
size_t	ln_index(char *buf);
char	*ft_strjoin(char *line, char *buf);
size_t	catnate(char *dst, char *src, size_t dstsize);
char	*strsub(char *s, unsigned int start, size_t len);

#endif