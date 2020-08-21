/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 10:29:21 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/10 21:41:14 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 45
# endif

# define F_EOF 0
# define F_ERROR -1
# define F_NEXT_LN 1

int		get_next_line(int fd, char **line);

char	*ft_cut_str(char **line, char *buf);
int		ft_if_next_line(char *buf);
void	ft_free_str(char **str);
char	*ft_newstr_from_two(char *line, char *buf);

#endif
