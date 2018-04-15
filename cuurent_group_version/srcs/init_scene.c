/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:08:52 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/15 00:31:05 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	init_mlx(t_params *params)
{
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

void    create_shapes(t_params *params, char *forme)
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
	params->eye.orientation = set_vector(0,1,0);
	params->nb_objects = get_nb_objects(params);
	init_objects(params);
	ft_putstr("\nInitialisation scene OK..");
}
