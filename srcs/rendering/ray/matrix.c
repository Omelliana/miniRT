/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:13:51 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/14 22:10:59 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		init_matrix_row(t_matrix *matrix, int i, t_axis vector)
{
	matrix->dimension[i][0] = vector.x;
	matrix->dimension[i][1] = vector.y;
	matrix->dimension[i][2] = vector.z;
}

t_matrix		view(t_axis camera, t_axis start)
{
	t_axis		origin;
	t_axis		vector_x;
	t_axis		vector_z;
	t_matrix	matrix;

	origin = init_vector(0, 1, 0);
	normal(&origin);
	vector_x = perpendicul_vec(origin, camera);
	normal(&vector_x);
	vector_z = perpendicul_vec(camera, vector_x);
	normal(&vector_z);
	init_matrix_row(&matrix, 0, vector_x);
	init_matrix_row(&matrix, 1, vector_z);
	init_matrix_row(&matrix, 2, camera);
	init_matrix_row(&matrix, 3, start);
	return (matrix);
}

static double	multiply(t_matrix matr, int ind, t_axis vec)
{
	double		res;

	res = (vec.x * matr.dimension[0][ind]) + (vec.y * matr.dimension[1][ind]) \
	+ (vec.z * matr.dimension[2][ind]) + matr.dimension[3][ind];
	return (res);
}

t_axis			matrix_multiply(t_axis vector, t_matrix matrix)
{
	t_axis		vec;

	vec.x = multiply(matrix, 0, vector);
	vec.y = multiply(matrix, 1, vector);
	vec.z = multiply(matrix, 2, vector);
	return (vec);
}
