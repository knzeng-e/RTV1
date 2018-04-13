/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:08:52 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/14 00:13:32 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	init_mlx(t_params *params)
{
	if (params->parsing_on)
		parse_file(params);

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
}

void	init_scene(t_params *params)
{
	init_mlx(params);
	params->eye.from = set_vector(0, 1, 0);
	//params->eye.to = set_vector(-0.5, -3, -11);	
	params->eye.to = set_vector(0, 0, -1);	
    params->rotation = set_vector(0, 0, 0);
    params->translation = set_vector(0, 0, 0);
	params->nb_objects = get_nb_objects(params);
	create_sphere(params);
	create_plane(params);
	create_cylinder(params);
	create_cone(params);
	put_light(params, -9, 6, -4);
	init_objects(params);
}
