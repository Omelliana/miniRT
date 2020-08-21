/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 21:04:00 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/12 02:46:01 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_new_word(char *part, char const *set)
{
	char		*st_start;

	st_start = part;
	while (*part && (!ft_is_set(*part, set)))
		part++;
	*part = '\0';
	return (ft_strdup(st_start));
}

static size_t	ft_words_count(char const *str, char const *set)
{
	size_t		count;

	count = 0;
	while (*str)
	{
		if (!ft_is_set(*str, set))
			count += 1;
		while ((!ft_is_set(*str, set)) && *(str + 1))
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

static char		**ft_new_arr(char *str, char const *set, size_t count)
{
	size_t		ind;
	char		**array;
	char		*part;

	ind = 0;
	if (!(array = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	while (count > ind)
	{
		while (ft_is_set(*str, set))
			str += 1;
		if (*str != '\0')
		{
			if (!(part = ft_new_word(str, set)))
				return (ft_free_arr(array));
			array[ind++] = part;
			str += ft_strlen(part) + 1;
		}
	}
	array[ind] = NULL;
	return (array);
}

char			**ft_split_set(char const *s, char const *set)
{
	char		**array;
	char		*copy_str;

	if (!s)
		return (NULL);
	if (!(copy_str = ft_strdup((char *)s)))
		return (NULL);
	array = ft_new_arr(copy_str, set, ft_words_count(copy_str, set));
	free(copy_str);
	return (array);
}
