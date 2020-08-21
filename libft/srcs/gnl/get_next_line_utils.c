/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 10:29:10 by bodysseu          #+#    #+#             */
/*   Updated: 2020/06/09 18:57:35 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_if_next_line(char *buf)
{
	int		ind;

	ind = 0;
	if (buf)
	{
		while (buf[ind])
		{
			if (buf[ind] == '\n')
				return (F_NEXT_LN);
			ind += 1;
		}
	}
	return (F_EOF);
}

void		ft_free_str(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

char		*ft_newstr_from_two(char *line, char *buf)
{
	int		len_st1;
	int		len_st2;
	char	*new_str;

	len_st1 = 0;
	len_st2 = 0;
	if (line)
		while (line[len_st1])
			len_st1++;
	while (buf[len_st2])
		len_st2++;
	if (!(new_str = (char *)malloc(sizeof(char) * (len_st1 + len_st2 + 1))))
		return (NULL);
	len_st1 = 0;
	if (line)
		while (line[len_st1])
		{
			new_str[len_st1] = line[len_st1];
			len_st1++;
		}
	len_st2 = 0;
	while (buf[len_st2])
		new_str[len_st1++] = buf[len_st2++];
	new_str[len_st1] = '\0';
	return (new_str);
}

char		*ft_cut_str(char **line, char *buf)
{
	int		ind;
	char	*tmp_str;
	char	*result_str;

	ind = 0;
	tmp_str = ft_newstr_from_two(*line, buf);
	while (tmp_str[ind] != '\n')
		ind++;
	tmp_str[ind] = '\0';
	ft_free_str(line);
	*line = ft_newstr_from_two(tmp_str, "");
	result_str = ft_newstr_from_two(&tmp_str[ind + 1], "");
	ft_free_str(&tmp_str);
	return (result_str);
}
