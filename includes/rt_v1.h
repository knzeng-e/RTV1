/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_v1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:32:50 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/11/23 02:45:19 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_V1_H
# define RT_V1_H
# define WIDTH 800
# define HEIGHT 640
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define UP_KEY 126
# define DOWN_KEY 125
# define V_KEY 9
# define B_KEY 11
# define J_KEY 38
# define RADIUS 20.0
# define OK 0
# define MAX_DISTANCE 20000
# define NO_INTERSECTION 0
# define IS_INTERSECTION 1
# define MALLOC_PARAMS_ERROR -1
# include "../mlx/mlx.h"
# include <libft.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "rayon.h"
# include "sphere.h"
# define free(aa) {printf("[%s][ligne %d] Liberation bloc %s a %p\n",__FILE__,__LINE__,#aa,aa);free(aa);}


typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

typedef struct	s_cylindre
{
	double		rayon;
	double		hauteur;
}				t_cylindre;

typedef struct	s_view
{
	double		view_width;
	double		view_height;
	double		dist;
}				t_view;

typedef struct	s_camera
{
//	t_view		view;
	double		view_width;
	double		view_height;
	double		view_dist;
	t_vect		view_left_up;
	t_vect		cam_pos;
	t_vect		vect_dir;
	t_vect		up_vect;
	t_vect		right_vect;
//	t_vect		viewpoint;
}				t_camera;

typedef struct	s_plane
{
	t_vect		position;
	t_vect		normale;
	t_vect		distance;
	t_color		color;
}				t_plane;

typedef struct	s_params
{
	t_camera	eye;
	t_sphere	sphere;
	t_sphere	sphere2;
	t_sphere	sphere3;
	t_ray		*tab_rays[WIDTH][HEIGHT];
	t_vect		light;
	t_plane		*plane;
	double		x_indent;
	double		y_indent;
	double		x_resolution;
	double		y_resolution;
	/*MLX PARAMS*/
	void		*mlx;
	void		*win;
	int			*ptr_img;
	int			*img_data;
	int			bpp;
	int			size_line;
	int			endian;
	int			rays_to_free;
	int			ray_depth;
	int			t;
}				t_params;

typedef struct	s_light
{
	t_point		position;
	double		bright;
}				t_light;

typedef struct	s_object
{
	int			id;
	int			type;
	union
	{
		t_sphere	*sphere;
		t_plane	*plane;
	} current_object;
}				t_object;

int				expose_hook(t_params *params);
int				mouse_hook(int button, int x, int y, t_params *params);
int				key_hook(int keycode, t_params *params);
int				track_ray(t_params *params);
int				throw_ray(t_ray *ray);
int				ft_free(t_params *params);
void			set_origin(int i, int j, t_ray *ray, t_params *params);
void			init_scene(t_params *params);
void			set_view(t_params *params);
void			ray_equation(t_ray *ray);
int				sphere_intersect(t_ray *ray, t_sphere sphere, t_params *params);
int				plane_intersect(t_ray *ray, t_plane *plane, t_params *params);
double			dot_product(t_vect vect1, t_vect vect2);
t_vect			cross_product(t_vect vect1, t_vect vect2);
#endif
