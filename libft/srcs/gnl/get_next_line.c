/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 17:51:08 by bodysseu          #+#    #+#             */
/*   Updated: 2020/06/09 18:57:36 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_remain(char **work_str, char **line)
{
	if (*line)
	{
		if (ft_if_next_line(*line))
		{
			ft_free_str(work_str);
			*work_str = ft_cut_str(line, "");
			return (F_NEXT_LN);
		}
	}
	else
		*line = ft_newstr_from_two("", "");
	ft_free_str(work_str);
	return (F_EOF);
}

static	int		ft_read_str(char *buf, char **work_str, char **line)
{
	char			*tmp_str;

	if (ft_if_next_line(buf))
	{
		ft_free_str(work_str);
		*work_str = ft_cut_str(line, buf);
		ft_free_str(&buf);
		return (F_NEXT_LN);
	}
	tmp_str = *line;
	*line = ft_newstr_from_two(*line, buf);
	ft_free_str(&tmp_str);
	return (F_EOF);
}

int				get_next_line(int fd, char **line)
{
	ssize_t			nl_result;
	char			*buf;
	static char		*work_str[4096];
	int				ft_read_res;

	if ((!line) || (fd < 0) || (BUFFER_SIZE <= 0))
		return (F_ERROR);
	nl_result = 0;
	ft_read_res = 0;
	*line = ft_newstr_from_two(work_str[fd], "");
	if (!(buf = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (F_ERROR);
	while ((nl_result = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[nl_result] = '\0';
		ft_read_res = ft_read_str(buf, &work_str[fd], line);
		if (ft_read_res > 0)
			return (F_NEXT_LN);
	}
	ft_free_str(&buf);
	if (nl_result < 0)
		return (F_ERROR);
	return (ft_remain(&work_str[fd], line));
}
