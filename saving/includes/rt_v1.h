/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_v1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:32:50 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/03/24 15:35:07 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_V1_H
# define RT_V1_H
# define WIDTH 800
//# define WIDTH 300
# define HEIGHT 640
//# define HEIGHT 300
# define ACC 0.001
# define AMBIANT_LIGHT 0.2
# define DIFFUSE_LIGHT 0.8
# define SPECULAR 10000
# define SHININESS 128
# define NB_SPHERES 4
# define NB_PLANES 1
# define NB_CYLINDERS 1
# define NB_LIGHTS 1
# define NB_CONES 0
# define NB_OBJECTS NB_PLANES + NB_SPHERES + NB_CYLINDERS + NB_CONES + NB_LIGHTS
# define NB_ACTIVE_OBJ NB_PLANES + NB_SPHERES + NB_CYLINDERS + NB_CONES
# define NB_SPHERES_PARAMS 4
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define UP_KEY 126
# define DOWN_KEY 125
# define MOVE_DIST 0.3
# define V_KEY 9
# define B_KEY 11
# define R_KEY 15
# define J_KEY 38
# define I_KEY 34
# define L_KEY 37
# define SPACE_KEY 49
# define ZOOM_IN 69
//# define ZOOM_IN 44
# define ZOOM_OUT 78
//# define ZOOM_OUT 24
# define RADIUS 20.0
# define OK 0
# define FREE_OK 0
# define MAX_DISTANCE 20000
# define INVALID_OBJECT 0
# define INVALID_DESCRIPTION 0
# define NO_INTERSECTION 0
# define IS_INTERSECTION 1
# define CORRECT_OBJECT_DESCRIPTION 1
# define ERROR_OBJECT_DESCRIPTION 0
# define ERROR_NB_PARAMS 0
# define MALLOC_PARAMS_ERROR -1
# define ERROR_OPEN -1
# define FREE_ERROR -4
# define MALLOC_ERROR -3
# define FOV 30
# define MAX_FOV 150
# define RED 0x00FF0000
# define TRUE 1
# define FALSE 0
//# define GREEN 0x0000FF00
# define GREEN 0x00088e40
# define BLUE 0x000000FF
# define YELLOW 0x00FFFF00
# define MALLOC_TRANSFORM_ERROR -2
# define PARSE_OK 1
# define PARSE_ERROR_MESSAGE "There is an Error in line "
# include "../mlx/mlx.h"
# include <libft.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <pthread.h>
# include "rayon.h"
# include "sphere.h"
# define free(aa) {printf("[%s][ligne %d] Liberation bloc %s a %p\n",__FILE__,__LINE__,#aa,aa);free(aa);}
# define RGB(r, g, b)(256 * 256 * (unsigned int)(r) + 256 * (unsigned int)(g) + (unsigned int)(b))

typedef struct	s_view
{
	double		view_width;
	double		view_height;
	double		dist;
}				t_view;

typedef struct	s_color
{
	int			red;
	int			green;
	int			blue;
}				t_color;

typedef struct	s_vect4
{
	double		vect_x;
	double		vect_y;
	double		vect_z;
	double		vect_w;
}				t_vect4;

typedef struct	s_matrix
{
	double		mat[4][4];
}				t_matrix;

typedef struct	s_camera
{
	t_view		viewpoint;
	t_vect		view_left_up;
	t_vect		cam_pos;
	t_vect		vect_dir;
	t_vect		up_vect;
	t_vect		right_vect;
	t_vect		forward_vect;
	t_matrix	cam_to_world;
//	t_vect		viewpoint;
}				t_camera;

typedef struct	s_cylinder
{
	double		radius;
	double		hauteur;
	double		specular;
	t_vect		center;
	t_vect		axis;
	t_vect		top;
	t_vect		bottom;
	t_color		color;
}				t_cylinder;

typedef struct	s_cone
{
	t_vect		center;
	double		angle;
	double		specular;
	t_color		color;
}				t_cone;



typedef struct	s_plane
{
	t_vect		position;
	t_vect		normale;
	t_vect		distance;
	t_color		color;
	double		specular;
}				t_plane;


typedef struct	s_transform
{
	double		angle_rotation;
	t_matrix	x_rotation;
	t_matrix	y_rotation;
	t_matrix	z_rotation;
	t_matrix	translation;
}				t_transform;

typedef struct	s_light
{
	t_vect		position;
	t_color		color;
	double		intensity;
	double		diffuse_light;
	int			is_selected;
	enum		e_type
	{
		POINT,
		DIRECTIONAL,
		AMBIANT
	}			t_type;
}				t_light;

typedef struct		s_object t_object;

struct				s_object
{
	int				id;
	int				is_set;
	double			specular;
	t_vect			position;
	t_color			color;
	enum
	{
		SPHERE = 1,
		PLANE,
		CYLINDER,
		CONE,
		LIGHT
	}				item;
	union
	{
		t_cone		*cone;
		t_cylinder	*cylinder;
		t_light		*light;
		t_plane		*plane;
		t_sphere	*sphere;
	}				type;
	struct s_object	*next;
};

typedef struct		s_params
{
	t_camera		eye;
	t_sphere		sphere_list[NB_SPHERES];
	t_plane			plane_list[NB_PLANES];
	t_cylinder		cylinder_list[NB_CYLINDERS];
	t_cone			cone_list[NB_CONES];
	t_ray			*tab_rays[WIDTH][HEIGHT];
	t_light			light[NB_LIGHTS];
	t_plane			*plane;
	t_plane			*vertical_plane;
	t_list			*obj_list;
	t_object		*objects;
	t_object		**objects_ptr;
	t_object		current_obj;
	t_light			current_light;
	t_vect			current_normal;
	t_vect			light_vector;
	t_transform		transforms;
	t_matrix		transform_matrx;
	double			x_indent;
	double			y_indent;
	double			x_resolution;
	double			y_resolution;
	double			fov;
	double			specularity;
	/*MLX PARAMS*/
	void			*mlx;
	void			*win;
	int				*ptr_img;
	char			*img_data;
	char			**line_content;
	int				fd;
	int				bpp;
	int				size_line;
	int				endian;
	int				rays_to_free;
	//int				ray_depth;
	double			ray_depth;
	int				t;
	int				color;
	int				nb_objects;
	int				current_index;
	int				current_sphere_index;
	int				current_plane_index;
	int				current_cylinder_index;
	int				current_cone_index;
	int				current_light_index;
	int				vector_lenght;
	int				other_intersect;
}					t_params;

int				expose_hook(t_params *params);
int				mouse_hook(int button, int x, int y, t_params *params);
int				key_hook(int keycode, t_params *params);
int				track_ray(t_params *params);
int				throw_ray(t_ray *ray);
int				ft_free(t_params *params);
int				is_shadowed(t_vect intersection, t_params *params, t_object *obj);
int				intersect(t_ray *ray, t_object *obj, t_params *params);
int				sphere_intersect(t_ray *ray, t_sphere sphere, t_params *params);
int				cylinder_intersect(t_ray *ray, t_cylinder *cyl, t_params *params);
int				plane_intersect(t_ray *ray, t_plane *plane, t_params *params);
int				cone_intersect(t_ray *ray, t_cone *cone, t_params *params);
int				check_sphere_params(t_params *params);
int				check_plane_params(t_params *params);
int				check_cylinder_params(t_params *params);
int				check_cone_params(t_params *params);
int				check_light_params(t_params *params);
int				couleur(double angle);
int				get_color(t_color color);
int				rgb_to_int(int r, int g, int b);
int				calc_color(int color, double intensity);
int				get_nb_objects(t_params *params);
int				get_sphere_position(t_params *params, char **infos);
int				get_obj_color(t_params *params, char **infos, int object_id);
int				ft_isnumber(char *number);

void			draw_pixel(t_params *params, int i, int j, int color);
void			set_origin(int i, int j, t_ray *ray, t_params *params);
void			init_mlx(t_params *params);
void			init_scene(t_params *params);
void			init_objects(t_params *params);
void			set_camera(t_ray *ray, t_params *params, int i, int j);
void			set_camera_look_at(t_ray *ray, t_params *params, t_vect *from, t_vect *to);
void			init_transform_matrices(t_transform *transforms);
void			parse_file(t_params *params);
void			set_view(t_params *params);
void			ray_equation(t_ray *ray);
void			ray_normalize(t_vect *vect);
void			set_x_rotation(t_transform *transforms);
void			set_y_rotation(t_transform *transforms);
void			set_z_rotation(t_transform *transforms);
void			save_intersection(t_ray *ray);
void			set_sphere(t_object *current_obj, t_params *params, int cpt_spheres);
void			save_spheres(t_object *current_obj, t_params *params, int *cpt_objects);
void			set_plane(t_object *current_obj, t_params *params, int cpt_planes);
void			save_planes(t_object *current_obj, t_params *params, int *cpt_objects);
void			set_light(t_object *current_obj, t_params *params, int cpt_lights);
void			save_lights(t_object *current_obj, t_params *params, int *cpt_objects);
void			set_cylinder(t_object *current_obj, t_params *params, int cpt_cylinders);
void			save_cylinders(t_object *current_obj, t_params *params, int *cpt_objects);
void			set_cone(t_object *current_obj, t_params *params, int cpt_cones);
void			save_cones(t_object *obj, t_params *params, int *cpt_objects);
void			save_sphere_coord(t_params *params, char *infos, int nb_coord);
void			show_object_type(t_object *current_obj);
void			print_objects(t_object *objects);
void			init_objects(t_params *params);
void			clamp(int *r, int *g, int *b);
double			radians(double angle);
double			get_length(t_vect *vect);
double			dot_product(t_vect vect1, t_vect vect2);
double			get_specular(t_vect normal, t_ray *ray, t_params *params);
double			shading(t_ray *ray, t_params *params);
double			max(double nbre1, double nbre2);
t_vect			rotate_x_axis(t_vect *vect, double angle, t_transform *transform);
t_vect			rotate_y_axis(t_vect *vect, double angle, t_transform *transform);
t_vect			rotate_z_axis(t_vect *vect, double angle, t_transform *transform);
t_vect			cross_product(t_vect vect1, t_vect vect2);
t_vect			get_normal(t_vect intersection, t_sphere sphere);
t_vect			vect_sub(t_vect vect1, t_vect vect2);
t_vect			vect_divide(t_vect vect, double cste);
t_vect			vect_multiply(t_vect vect, double cste);
t_vect			vect_add(t_vect vect1, t_vect vect2);
t_vect			set_vector(double x, double y, double z);
t_vect4			set_homogen(t_vect *vect);
t_vect4			vect_matrx_multiply(t_vect4 *vect, t_matrix *mat);
t_matrix		matrix_multiply(t_matrix *mat1, t_matrix *mat2);
t_color			set_color(double red, double green, double blue);
t_color			get_rgb(int color);
#endif
