/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 21:12:28 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/19 23:23:16 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "../libft/includes/libft.h"
# include "pixels.h"

typedef enum		e_object_type
{
	SPHERE,
	PLANE,
	SQUARE,
	CYLINDER,
	TRIANGLE
}					t_object_type;

typedef struct		s_object
{
	void			*ptr;

	t_frgb			color;
	t_object_type	type;
}					t_object;

typedef struct		s_sphere
{
	float			radius;

	t_axis			coord;
}					t_sphere;

typedef struct		s_plane
{
	t_axis			vector;
	t_axis			coord;
}					t_plane;

typedef struct		s_square
{
	double			size;

	t_axis			coord;
	t_axis			vector;
}					t_square;

typedef struct		s_triangle
{
	t_axis			first;
	t_axis			second;
	t_axis			third;
}					t_triangle;

typedef struct		s_cylindr
{
	double			radius;
	double			height;

	t_axis			coord;
	t_axis			vector;
}					t_cylindr;

typedef struct		s_fline
{
	char			*gnl;
	char			**parse;
}					t_fline;

typedef struct		s_intersect
{
	t_ray			ray;
	t_axis			impact_point;
	t_axis			impact_normal;
	t_object		*closest;
}					t_intersect;

int					intersect_with_object(t_list *objects, t_ray ray,
					t_object **closest, double *t_min);
int					intersect_sphere(t_sphere sphere, t_ray ray, double *t);
int					intersect_plane(t_plane plane, t_ray ray, double *t);
int					intersect_square(t_square square, t_ray ray, double *t);
int					intersect_triangle(t_triangle triangle,
					t_ray ray, double *t);
int					intersect_cylindr(t_cylindr cylinder, t_ray ray, double *t);

t_intersect			new_inter(t_axis impact_point, t_axis impact_normal,
					t_object *closest);

t_axis				get_normal(t_axis point, t_object *object);

#endif
