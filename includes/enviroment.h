/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroment.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 05:38:49 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/21 16:01:18 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIROMENT_H
# define ENVIROMENT_H

# include "objects.h"

typedef struct		s_camera
{
	int				fov;

	t_axis			coord;
	t_axis			vector;
}					t_camera;

typedef struct		s_light
{
	double			bright;

	t_axis			coord;
	t_frgb			rgb;
}					t_light;

typedef struct		s_scene
{
	int				camera;
	int				save;
	int				filter;

	t_resolution	res;
	t_ambient_ligth	amb;
	t_list			*cam_list;
	t_list			*light_list;
	t_list			*obj_list;
}					t_scene;

t_camera			switch_camera(t_scene *scene);
t_frgb				shade(t_scene *scene, t_object *closest,
						t_ray ray, double t_min);
t_frgb				light_color(t_light light, t_intersect inter,
						t_scene scene);

#endif
