/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:08:52 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/16 09:47:09 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	init_objects(t_params *params)
{
	int			cpt;
	t_object	*current_obj;

	cpt = -1;
	while (++cpt < params->nb_objects)
	{
		current_obj = params->objects;
		if (params->nb_cylinders > 0)
			save_cylinders(current_obj, params, &cpt);
		if (params->nb_planes > 0)
			save_planes(current_obj, params, &cpt);
		if (params->nb_cones > 0)
			save_cones(current_obj, params, &cpt);
		if (params->nb_spheres > 0)
			save_spheres(current_obj, params, &cpt);
		save_lights(current_obj, params, &cpt);
	}
	current_obj = NULL;
}

void	put_light(t_params *params, double x_pos, double y_pos, double z_pos)
{
	int		index;

	params->current_light_index = 0;
	params->nb_lights = 2;
	index = -1;
	while (++index < NB_LIGHTS)
	{
		if (index == 0)
		{
			params->light[index].position = set_vector(x_pos, y_pos, z_pos);
			params->light[index].intensity = 15;
			params->light[index].diffuse_light = DIFFUSE_LIGHT;
			params->light[index].is_selected = 0;
			params->light[index].color = set_color(0xFF, 0xFF, 0xFF);
		}
		else
		{
			params->light[index].position = set_vector(-x_pos, 9, -22);
			params->light[index].intensity = 15;
			params->light[index].diffuse_light = DIFFUSE_LIGHT;
			params->light[index].is_selected = 0;
			params->light[index].color = set_color(0xFF, 0xFF, 0xFF);
		}
	}
}

void	init_mlx(t_params *params)
{
	params->win = mlx_new_window(params->mlx, WIDTH, HEIGHT, "RTV1");
	params->ptr_img = mlx_new_image(params->mlx, WIDTH, HEIGHT);
	params->img_data = mlx_get_data_addr(params->ptr_img, \
			&(params->bpp), &(params->size_line), &(params->endian));
	params->fov = FOV;
	params->current_index = 0;
	params->objects = (t_object *)malloc(sizeof(t_object));
	if (params->objects == NULL)
		exit(MALLOC_ERROR);
	params->objects->next = NULL;
	params->objects->is_set = 0;
	params->objects->id = params->current_index;
	params->specularity = 400;
}

void	create_shapes(t_params *params, char *forme)
{
	if (!ft_strcmp(forme, "sphere") || !ft_strcmp(forme, "all"))
		create_sphere(params);
	if (!ft_strcmp(forme, "plane") || !ft_strcmp(forme, "all"))
		create_plane(params);
	if (!ft_strcmp(forme, "cylinder") || !ft_strcmp(forme, "all"))
		create_cylinder(params);
	if (!ft_strcmp(forme, "cone") || !ft_strcmp(forme, "all"))
		create_cone(params);
	ft_putstr("\nShape(s) created..");
}

void	init_scene(t_params *params, char *forme)
{
	init_mlx(params);
	params->eye.from = set_vector(0, 0, 0);
	params->eye.to = set_vector(0, 0, -21);
	params->nb_spheres = 0;
	params->nb_cylinders = 0;
	params->nb_cones = 0;
	params->nb_planes = 0;
	create_shapes(params, forme);
	put_light(params, -9, 6, -4);
	params->eye.orientation = set_vector(0, 1, 0);
	params->nb_objects = get_nb_objects(params);
	init_objects(params);
    rotate_cone(&params->cone_list[0], set_vector(0, 0, 42), params);
    rotate_cylinder(&params->cylinder_list[0], set_vector(0, 0, 0), params);
    translate_sphere(&params->sphere_list[0], set_vector(0, 0, 0));
}
