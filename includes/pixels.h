/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 01:39:28 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/21 13:54:51 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXELS_H
# define PIXELS_H

# define PIXEL_DATA_OFFSET 54
# define HEADER_SIZE 40
# define PLANES 1
# define BITS_PER_PIXEL 24

typedef struct		s_int_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_float_rgb
{
	float			r;
	float			g;
	float			b;
}					t_frgb;

typedef	struct		s_buffer
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_buffer;

typedef struct		s_resolution
{
	int				x;
	int				y;
}					t_resolution;

typedef struct		s_ambient_ligth
{
	double			ratio;
	t_frgb			rgb;
}					t_ambient_ligth;

typedef struct		s_axis
{
	double			x;
	double			y;
	double			z;
}					t_axis;

typedef	struct		s_ray
{
	t_axis			start;
	t_axis			direct;
}					t_ray;

typedef struct		s_matrix
{
	double			dimension[4][4];
}					t_matrix;

typedef struct		s_params
{
	double			a;
	double			b;
	double			c;
	double			determ;
}					t_params;

t_axis				init_vector(double x, double y, double z);
void				normal(t_axis *vec);
double				vector_len(t_axis vector);
double				vector_dot(t_axis a, t_axis b);
t_axis				perpendicul_vec(t_axis vec_1, t_axis vec_2);
t_axis				vector_difference(t_axis vec1, t_axis vec2);
t_axis				vector_summa(t_axis vector_1, t_axis vector_2);
t_axis				vector_multiply(t_axis vector, double x);

t_matrix			view(t_axis camera, t_axis start);
t_axis				matrix_multiply(t_axis vector, t_matrix matrix);

t_ray				create_ray(t_axis origin, t_axis direction);

int					color_to_int(t_rgb color);
int					frgb_to_int(t_frgb a);
t_frgb				int_to_frgb(int color);
t_rgb				int_to_rgb(int color);

t_frgb				color_multiply(t_frgb a, t_frgb b);
t_frgb				color_coefficient(t_frgb f_color, double coeff);
t_frgb				color_summ(t_frgb a, t_frgb b);

int					solve_equation(t_params params, double *x1, double *x2);

t_buffer			**create_buff(int x, int y);
t_buffer			get_pixels(int color);
void				free_buff(t_buffer **buff, int y);

void				write_to_bmp(char *filename, unsigned int width,
					unsigned int height, t_buffer **buffer);

#endif
