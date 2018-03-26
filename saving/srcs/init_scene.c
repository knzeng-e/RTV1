/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:08:52 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/03/26 03:01:40 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	init_mlx(t_params *params)
{
	//parse_file("test");
	/*Penser à proteger le mlx_init*/
	params->win = mlx_new_window(params->mlx, WIDTH, HEIGHT, "RTV1");
	params->ptr_img = mlx_new_image(params->mlx, WIDTH, HEIGHT);
	params->img_data = mlx_get_data_addr(params->ptr_img, \
			&(params->bpp),  &(params->size_line), &(params->endian));
	params->fov = FOV;
	params->current_index = 0;
	params->objects = (t_object *)malloc(sizeof(t_object));
	if (params->objects == NULL)
		exit (MALLOC_ERROR);
	params->objects->next = NULL;
	params->objects->is_set = 0;
	params->objects->id = params->current_index;
	params->specularity = 400;
}

void	create_sphere(t_params *params)
{
	int	cpt;

	cpt = -1;
	while (++cpt < NB_SPHERES)
		params->sphere_list[cpt].is_selected = 0;
	/* YELLOW */
	params->sphere_list[0].rayon = 0.5;
	params->sphere_list[0].center = set_vector(2.1, -3.4, -22);
	params->sphere_list[0].specular = 500;
	params->sphere_list[0].color = rgb_to_int(0xff, 1, 16);
	/* GREEN */
	params->sphere_list[1].rayon = 0.6;
	params->sphere_list[1].center = set_vector(-0.8, -3.3, -15);
	params->sphere_list[1].color = rgb_to_int(0, 1, 40);
	params->sphere_list[1].specular = 500;
	/* BLUE */
	params->sphere_list[2].rayon = 0.8;
	params->sphere_list[2].center = set_vector(0.5, -3, -22);
	params->sphere_list[2].color = rgb_to_int(0, 0, 166);
	params->sphere_list[2].specular = 500;
	/* RED */
	params->sphere_list[3].rayon = 0.9;
	params->sphere_list[3].center = set_vector(-3.3, -3, -19);
	params->sphere_list[3].color = rgb_to_int(80, 0, 3);
	params->sphere_list[3].specular = 242;
}

void	create_plane(t_params *params)
{
	if ((params->plane = (t_plane *)malloc(sizeof(t_plane))) == NULL)
		exit(ft_free(params));

	if ((params->vertical_plane = (t_plane *)malloc(sizeof(t_plane))) == NULL)
		exit(ft_free(params));
	/* Horizontal plane*/
	params->plane->position = set_vector(0, -4, 0);
	params->plane->normale = set_vector(0, 1, 0);
	params->plane->color = set_color(0xff, 0xff, 0xff);
	//params->plane->color = set_color(46, 46, 46);
	params->plane->specular = 6000;
	params->plane_list[0] = *params->plane;

	/* Vertical plane*/
	params->vertical_plane->position = set_vector(0, -4, -42);
	params->vertical_plane->normale = set_vector(0, 0, 1);
	params->vertical_plane->color = set_color(5, 5, 2);
	params->vertical_plane->specular = 0;
	/*params->plane_list[1] = *params->vertical_plane;*/
}

void	create_cylinder(t_params *params)
{
	//params->cylinder_list[0].center = set_vector(-6, -3, -50);
	params->cylinder_list[0].center = set_vector(-3, 0, -41);
	params->cylinder_list[0].axe = set_vector(0, 1, 0);
	params->cylinder_list[0].radius = 2;
	params->cylinder_list[0].size = 1;
	params->cylinder_list[0].specular = 100;
	params->cylinder_list[0].color = set_color(0x4a, 0x2a, 0x9f);
}

void	create_cone(t_params *params)
{
	params->cone_list[0].center = set_vector(5, 2, -52);
	params->cone_list[0].axe = set_vector(0, 1, 0);
	params->cone_list[0].size = 10;
	params->cone_list[0].angle = radians(10);
	params->cone_list[0].specular = 300;
	params->cone_list[0].color = set_color(0xff, 0x8f, 42);
	//params->cone_list[0].color = set_color(42, 42, 42);
}

void	put_light(t_params *params, double x_pos, double y_pos, double z_pos)
{
	t_light	*light;
	t_light	*light2;

	if ((light = (t_light *)malloc(sizeof(t_light))) == NULL)
		exit(0);

	if ((light2 = (t_light *)malloc(sizeof(t_light))) == NULL)
		exit(0);
	light->position = set_vector(x_pos, y_pos, z_pos);
	light->intensity = 15;
	light->diffuse_light = DIFFUSE_LIGHT;
	light->is_selected = 0;
	light->color = set_color(0xFF, 0xFF, 0xFF); 
	params->light[0] = *light;

	/*light2->position = set_vector(-x_pos, 5, -4);
	  light2->intensity = 300;
	  light2->diffuse_light = DIFFUSE_LIGHT;
	  light2->is_selected = 0;
	  light2->color = set_color(0xFF, 0xFF, 0xFF); 
	params->light[1] = *light2;*/
}

void	init_scene(t_params *params)
{
	init_mlx(params);
	//params->transforms = 
	params->other_intersect = 0;
	params->nb_objects = get_nb_objects(params);
	create_sphere(params);
	create_plane(params);
	create_cylinder(params);
	create_cone(params);
	put_light(params, 4, 16, -1);
	//put_light(params, -3.3, -3, -19);
	//params->sphere_list[3].center = set_vector(-3.3, -3, -19);
	init_objects(params);
}
