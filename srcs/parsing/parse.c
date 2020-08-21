/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 01:12:12 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/21 16:02:30 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	enviroment_type(char *param)
{
	if ((!ft_strcmp(param, "R")) || (!ft_strcmp(param, "A"))
	|| (!ft_strcmp(param, "c")) || (!ft_strcmp(param, "l")))
		return (1);
	else if ((!ft_strcmp(param, "sp"))
	|| (!ft_strcmp(param, "pl"))
	|| (!ft_strcmp(param, "sq"))
	|| (!ft_strcmp(param, "tr"))
	|| (!ft_strcmp(param, "cy")))
		return (2);
	return (0);
}

static void	parse_objects(t_scene *scene, t_fline line, char *param)
{
	if (!ft_strcmp(param, "sp"))
		parse_sphere(scene, line);
	else if (!ft_strcmp(param, "pl"))
		parse_plane(scene, line);
	else if (!ft_strcmp(param, "sq"))
		parse_square(scene, line);
	else if (!ft_strcmp(param, "tr"))
		parse_triangle(scene, line);
	else if (!ft_strcmp(param, "cy"))
		parse_cylindr(scene, line);
}

void		parse(t_scene *scene, t_fline line, char *param)
{
	int		type;

	type = enviroment_type(param);
	if (type == 1)
		parse_env(scene, line, param);
	else if (type == 2)
		parse_objects(scene, line, param);
	else if (param[0] == '#')
		;
	else if (!ft_strcmp(param, "BW"))
		scene->filter = 1;
	else
		error_exit("|Wrong parse parametr|");
}
