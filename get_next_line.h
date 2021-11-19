/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:32:29 by hmoubal           #+#    #+#             */
/*   Updated: 2021/11/16 22:21:09 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1,	char const *s2);
void	*ft_memcpy(void *dest,	const void *src,	size_t size);
size_t	ft_strlen(char const	*str);
#endif
