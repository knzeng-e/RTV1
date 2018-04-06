/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 18:20:13 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/06 13:33:00 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	create_sphere(t_params *params)
{
	int	cpt;

	params->current_sphere_index = 0;
	cpt = -1;
	while (++cpt < NB_SPHERES)
		params->sphere_list[cpt].is_selected = 0;
	/* YELLOW */
	params->sphere_list[0].rayon = 1.3;
	params->sphere_list[0].center = set_vector(3.5, -3.2, -10);
	//params->sphere_list[0].center = set_vector(0, 0, -11);
	params->sphere_list[0].specular = 242;
	params->sphere_list[0].color = rgb_to_int(0xff, 1, 42);
	/* GREEN */
	params->sphere_list[1].rayon = 1.4;
	params->sphere_list[1].center = set_vector(-0.4, -3, -8);
	params->sphere_list[1].color = rgb_to_int(142, 1, 81);
	params->sphere_list[1].specular = 250;
	/* POURPRE */
	params->sphere_list[2].rayon = 1.7;
	params->sphere_list[2].center = set_vector(-3.9, -2.4, -11);
	params->sphere_list[2].color = rgb_to_int(70, 0, 42);
	params->sphere_list[2].specular = 240;
	/* CYAN */
	params->sphere_list[3].rayon = 1.7;
	params->sphere_list[3].center = set_vector(3.3, -2, -17);
	params->sphere_list[3].color = rgb_to_int(142, 1, 283);
	params->sphere_list[3].specular = 242;
}

void	create_plane(t_params *params)
{
	params->current_plane_index = 0;
	if ((params->plane = (t_plane *)malloc(sizeof(t_plane))) == NULL)
		exit(ft_free(params));

	if ((params->vertical_plane = (t_plane *)malloc(sizeof(t_plane))) == NULL)
		exit(ft_free(params));
	/* Horizontal plane*/
	params->plane->position = set_vector(0, -4, 0);
	params->plane->normale = set_vector(0, 1, 0);
	params->plane->color = set_color(0xff, 0xff, 0xff);
	params->plane->specular = 600;
	params->plane_list[0] = *params->plane;
	/* Vertical plane*/
	params->vertical_plane->position = set_vector(0, -6, -32);
	params->vertical_plane->normale = set_vector(0, 0.2, 1);
	params->vertical_plane->color = set_color(5, 5, 2);
	params->vertical_plane->specular = 600;
}

void	create_cylinder(t_params *params)
{
	params->current_cylinder_index = 0;
	params->cylinder_list[0].center = set_vector(-3, 0, -20);
	params->cylinder_list[0].axe = set_vector(0, 1, 0);
	params->cylinder_list[0].radius = 3.7;
	params->cylinder_list[0].size = 1.7;
	params->cylinder_list[0].specular = 100;
	params->cylinder_list[0].color = set_color(0xa, 0xa, 0x2c);
}

void	create_cone(t_params *params)
{
	params->current_cone_index = 0;
	params->cone_list[0].center = set_vector(2, 8, -26);
	params->cone_list[0].axe = set_vector(0.4, 1, 0.2);
	params->cone_list[0].size = 12;
	params->cone_list[0].angle = radians(10);
	params->cone_list[0].specular = 300;
	params->cone_list[0].color = set_color(0xff, 0x8f, 42);
}

void	put_light(t_params *params, double x_pos, double y_pos, double z_pos)
{
	int	index;

	params->current_light_index = 0;
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
			/*Saving Light 2*/
			params->light[index].position = set_vector(-x_pos, 9, -22);
			params->light[index].intensity = 15;
			params->light[index].diffuse_light = DIFFUSE_LIGHT;
			params->light[index].is_selected = 0;
			params->light[index].color = set_color(0xFF, 0xFF, 0xFF);
		}
	}
}
