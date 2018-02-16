/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:08:52 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/02/16 22:41:14 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	create_sphere(t_params *params)
{
	int	cpt;

	cpt = -1;
	while (++cpt < NB_SPHERES)
		params->sphere_list[cpt].is_selected = 0;
	params->sphere_list[0].rayon = 0.5;
	params->sphere_list[0].center = set_vector(0.1, 2.1, -18);
	//params->sphere_list[0].color = 0x00FF00FF;
	params->sphere_list[0].color = rgb_to_int(0xff, 0xff, 66);
	params->sphere_list[1].rayon = 0.6;
	params->sphere_list[1].center = set_vector(-0.8, 0.5, -14);
	params->sphere_list[1].color = rgb_to_int(0, 1, 0);
	params->sphere_list[2].rayon = 0.8;
	params->sphere_list[2].center = set_vector(0.5, 1.7, -16);
	params->sphere_list[2].color = BLUE;
	params->sphere_list[3].rayon = 0.9;
	params->sphere_list[3].center = set_vector(-1.3, 1.3, -22);
	params->sphere_list[3].color = RED;
}

void	init_mlx(t_params *params)
{
	params->mlx = mlx_init();
	/*Penser à proteger le mlx_init*/
	params->win = mlx_new_window(params->mlx, WIDTH, HEIGHT, "RTV1");
	params->ptr_img = mlx_new_image(params->mlx, WIDTH, HEIGHT);
	params->img_data = mlx_get_data_addr(params->ptr_img, \
		&(params->bpp),  &(params->size_line), &(params->endian));
	params->fov = FOV;
	params->objects = (t_object *)malloc(sizeof(t_object));
	if (params->objects == NULL)
		exit (MALLOC_ERROR);
	params->objects->next = NULL;
	params->objects->is_set = 0;
	printf("\n\n[init_mlx] - Objects in adress ==> %p", params->objects);
}

void	create_plane(t_params *params)
{
	if ((params->plane = (t_plane *)malloc(sizeof(t_plane))) == NULL)
		exit(ft_free(params));
	
	if ((params->vertical_plane = (t_plane *)malloc(sizeof(t_plane))) == NULL)
		exit(ft_free(params));
	/*Init position*/
	params->plane->position = set_vector(0, -4, -445);
	//params->plane->position = set_vector(0, 0, -42);
	/*Init Normale*/
	params->plane->normale = set_vector(0, 1, 0);
	//params->plane->normale = set_vector(0, 0, -1);
	params->plane->color = set_color(21, 0xae, 0xFF);
	//params->plane->color = set_color(0xFF, 0, 0);
	params->plane_list[0] = *params->plane;

	/*Init position*/
	params->vertical_plane->position = set_vector(0, -4, -42);
	/*Init Normale*/
	params->vertical_plane->normale = set_vector(0, 0, -1);
//	params->vertical_plane->color = set_color(0xFF, 0, 0);
	params->vertical_plane->color = set_color(21, 0xae, 0xFF);
	/*params->plane_list[1] = *params->vertical_plane;*/
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
	light->intensity = 1.5;
	light->diffuse_light = DIFFUSE_LIGHT;
	light->specular_light = SPECULAR;
	light->shininess = SHININESS;
	light->is_selected = 0;
	light->color = set_color(0xFF, 0xFF, 0xFF); 
	params->light[0] = *light;

	light2->position = set_vector(-x_pos, 8, -10);
	light2->intensity = 1.5;
	light2->diffuse_light = DIFFUSE_LIGHT;
	light2->specular_light = SPECULAR;
	light2->shininess = SHININESS;
	light2->is_selected = 0;
	light2->color = set_color(0xFF, 0xFF, 0xFF); 
	params->light[1] = *light2;
}

void	init_scene(t_params *params)
{
	init_mlx(params);
	params->nb_objects = get_nb_objects(params);
	create_sphere(params);
	create_plane(params);
	put_light(params, -7, 12, -10);
	init_objects(params);
}
