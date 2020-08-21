/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:01:36 by bodysseu          #+#    #+#             */
/*   Updated: 2020/07/10 00:27:45 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_new_word(char *part, char c)
{
	char		*st_start;

	st_start = part;
	while (*part && (*part != c))
		part++;
	*part = '\0';
	return (ft_strdup(st_start));
}

static size_t	ft_words_count(char const *str, char del)
{
	size_t		count;

	count = 0;
	while (*str)
	{
		if (*str != del)
			count += 1;
		while (*str != del && *(str + 1))
			str += 1;
		str += 1;
	}
	return (count);
}

static char		**ft_free_arr(char **array)
{
	size_t		ind;

	ind = 0;
	while (array[ind])
	{
		free(array[ind]);
		ind++;
	}
	free(array);
	return (NULL);
}

static char		**ft_new_arr(char *str, char del, size_t count)
{
	size_t		ind;
	char		**array;
	char		*part;

	ind = 0;
	if (!(array = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	while (count > ind)
	{
		while (*str == del)
			str += 1;
		if (*str != '\0')
		{
			if (!(part = ft_new_word(str, del)))
				return (ft_free_arr(array));
			array[ind++] = part;
			str += ft_strlen(part) + 1;
		}
	}
	array[ind] = NULL;
	return (array);
}

char			**ft_split(char const *s, char c)
{
	char		**array;
	char		*copy_str;

	if (!s)
		return (NULL);
	if (!(copy_str = ft_strdup((char *)s)))
		return (NULL);
	array = ft_new_arr(copy_str, c, ft_words_count(copy_str, c));
	free(copy_str);
	return (array);
}
