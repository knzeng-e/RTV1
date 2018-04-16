/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 18:20:13 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/16 03:14:11 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	create_sphere(t_params *params)
{
	int	cpt;

	params->current_sphere_index = 0;
	params->nb_spheres = 4;
	cpt = -1;
	while (++cpt < params->nb_spheres)
		params->sphere_list[cpt].is_selected = 0;
	params->sphere_list[0].rayon = 1.2;
	params->sphere_list[0].center = set_vector(2.5, -3, -11.5);
	params->sphere_list[0].specular = 242;
	params->sphere_list[0].color = rgb_to_int(0xff, 1, 42);
	params->sphere_list[1].rayon = 1.3;
	params->sphere_list[1].center = set_vector(-0.5, -3, -11);
	params->sphere_list[1].color = rgb_to_int(142, 1, 81);
	params->sphere_list[1].specular = 250;
	params->sphere_list[2].rayon = 1.4;
	params->sphere_list[2].center = set_vector(-5, -2.4, -13);
	params->sphere_list[2].color = rgb_to_int(42, 0, 42);
	params->sphere_list[2].specular = 240;
	params->sphere_list[3].rayon = 1.1;
	params->sphere_list[3].center = set_vector(5.7, -2.7, -15);
	params->sphere_list[3].color = rgb_to_int(142, 1, 283);
	params->sphere_list[3].specular = 242;
}

void	create_plane(t_params *params)
{
	params->current_plane_index = 0;
	params->nb_planes = 1;
	if ((params->plane = (t_plane *)malloc(sizeof(t_plane))) == NULL)
		exit(-2);
	if ((params->vertical_plane = (t_plane *)malloc(sizeof(t_plane))) == NULL)
		exit(-2);
	params->plane->position = set_vector(0, -4, 0);
	params->plane->normale = set_vector(0, 1, 0);
	params->plane->color = set_color(0xff, 0xff, 0xff);
	params->plane->specular = 600;
	params->plane_list[0] = *params->plane;
	params->vertical_plane->position = set_vector(0, -6, -32);
	params->vertical_plane->normale = set_vector(0, 0.2, 1);
	params->vertical_plane->color = set_color(5, 5, 2);
	params->vertical_plane->specular = 600;
}

void	create_cylinder(t_params *params)
{
	params->current_cylinder_index = 0;
	params->nb_cylinders = 2;
	params->cylinder_list[0].center = set_vector(8, 6, -26);
	params->cylinder_list[0].axe = set_vector(0, 1, 0);
	params->cylinder_list[0].radius = 3.7;
	params->cylinder_list[0].hauteur = 21;
	params->cylinder_list[0].size = 0.8;
	params->cylinder_list[0].specular = 100;
	params->cylinder_list[0].color = set_color(0xfd, 0xbc, 0x2c);
	params->cylinder_list[1].center = set_vector(-6.5, 8, -29);
	params->cylinder_list[1].axe = set_vector(0, 1, 0);
	params->cylinder_list[1].radius = 3.7;
	params->cylinder_list[1].hauteur = 19;
	params->cylinder_list[1].size = 1.5;
	params->cylinder_list[1].specular = 100;
	params->cylinder_list[1].color = set_color(0x8f, 0xbc, 0xff);
}

void	create_cone(t_params *params)
{
	params->current_cone_index = 0;
	params->nb_cones = 2;
	params->cone_list[0].center = set_vector(1, 2.5, -25);
	params->cone_list[0].axe = set_vector(0, 1, 0);
	params->cone_list[0].size = 18;
	params->cone_list[0].hauteur = 12;
	params->cone_list[0].angle = radians(10);
	params->cone_list[0].specular = 300;
	params->cone_list[0].color = set_color(0x1e, 0x9e, 0xc4);
	params->cone_list[1].center = set_vector(-6.5, 8.2, -29);
	params->cone_list[1].axe = set_vector(0, 1, 0);
	params->cone_list[1].size = 10;
	params->cone_list[1].hauteur = -3;
	params->cone_list[1].angle = radians(10);
	params->cone_list[1].specular = 300;
	params->cone_list[1].color = set_color(0xff, 0, 62);
}
