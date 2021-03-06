/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 02:57:19 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/10 12:05:16 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	set_sphere(t_object *current_obj, t_params *params, int cpt_spheres)
{
	current_obj->type.sphere = &params->sphere_list[cpt_spheres];
	current_obj->item = SPHERE;
	current_obj->position = params->sphere_list[cpt_spheres].center;
	current_obj->color = get_rgb(params->sphere_list[cpt_spheres].color);
	current_obj->is_set = 1;
	current_obj->next = NULL;
	current_obj->id = params->current_index;
    params->sphere_list[cpt_spheres].id = current_obj->id;
    current_obj->specular = params->sphere_list[cpt_spheres].specular;
}

void	set_plane(t_object *current_obj, t_params *params, int cpt_planes)
{
    current_obj->type.plane = &params->plane_list[cpt_planes];
    current_obj->item = PLANE;
    current_obj->position = params->plane_list[cpt_planes].position;
    current_obj->color = params->plane_list[cpt_planes].color;
    current_obj->is_set = 1;
    current_obj->next = NULL;
    current_obj->id = params->current_index;
    params->plane_list[cpt_planes].id = current_obj->id;
    current_obj->specular = params->plane_list[cpt_planes].specular;
}

void	set_light(t_object *current_obj, t_params *params, int cpt_lights)
{
    current_obj->type.light = &params->light[cpt_lights];
    current_obj->item = LIGHT;
    current_obj->position = params->light[cpt_lights].position;
    current_obj->color = params->light[cpt_lights].color;
    current_obj->is_set = 1;
    current_obj->next = NULL;
    current_obj->id = params->current_index;
    params->light[cpt_lights].id = current_obj->id;
    current_obj->specular = params->light[cpt_lights].intensity;
}

void	set_cylinder(t_object *current_obj, t_params *params, int cpt_cylinders)
{
    current_obj->type.cylinder = &params->cylinder_list[cpt_cylinders];
    current_obj->item = CYLINDER;
    current_obj->position = params->cylinder_list[cpt_cylinders].center;
    current_obj->color = params->cylinder_list[cpt_cylinders].color;
    current_obj->is_set = 1;
    current_obj->next = NULL;
    current_obj->id = params->current_index;
    params->cylinder_list[cpt_cylinders].id = current_obj->id;
    current_obj->specular = params->cylinder_list[cpt_cylinders].specular;
}

void	set_cone(t_object *current_obj, t_params *params, int cpt_cones)
{
    current_obj->type.cone = &params->cone_list[cpt_cones];
    current_obj->item = CONE;
    current_obj->position = params->cone_list[cpt_cones].center;
    current_obj->color = params->cone_list[cpt_cones].color;
    current_obj->is_set = 1;
    current_obj->next = NULL;
    current_obj->id = params->current_index;
    params->cone_list[cpt_cones].id = current_obj->id;
    current_obj->specular = params->cone_list[cpt_cones].specular;
}
