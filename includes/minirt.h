/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:47:39 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/21 13:38:06 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include "../miniLibX/mlx.h"
# include "enviroment.h"

# define EPSILA 1e-6
# define FAR 1e30

typedef	enum	e_keys
{
	ESC = 53,
	LEFT = 123,
	RIGHT = 124
}				t_keys;

typedef	struct	s_image
{
	int			*addr;
	int			bits;
	int			line_len;
	int			endian;

	void		*img;
}				t_image;

typedef struct	s_minirt
{
	int			camera_number;

	void		*mlx;
	void		*win;

	t_image		image;
	t_scene		*scene;
}				t_minirt;

void			open_window(char *argv[]);

t_scene			*open_file(char *file_name, int save);

void			parse(t_scene *scene, t_fline line, char *param);
t_frgb			parse_frgb(char *split);
t_axis			parse_axis(char *split, int orientation);
void			parse_env(t_scene *scene, t_fline line, char *param);
void			parse_sphere(t_scene *scene, t_fline line);
void			parse_plane(t_scene *scene, t_fline line);
void			parse_square(t_scene *scene, t_fline line);
void			parse_triangle(t_scene *scene, t_fline line);
void			parse_cylindr(t_scene *scene, t_fline line);

void			free_parse(t_fline *line);
void			ft_strdel(char **as);
void			free_struct(t_scene *scene);
void			free_sstr(char **line);

void			rendering(int camera_number, t_minirt *mrt);
int				ray_tracing(t_scene *scene, t_ray ray);
t_ray			get_ray(int x, int y, t_scene *scene);

int				key_press(int key, t_minirt *mrt);
int				exit_ok(t_minirt *mrt);
void			error_exit(char *error_output);

void			swap_bubble(double *a, double *b);
double			ft_sqr(double n);

void			save(char *argv[]);
void			create_bmp_image(t_minirt *rt, char *file_name);

#endif
