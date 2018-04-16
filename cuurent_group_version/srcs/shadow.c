/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 08:30:37 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/16 08:02:21 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

double	shading(t_ray *ray, t_params *params)
{
	t_object	*light;
	double		angle;
	double		lightning;

	lightning = 0;
	light = params->objects;
	while (light && light->item != LIGHT)
		light = light->next;
	while (light && light->item == LIGHT)
	{
		params->current_light.intensity = light->specular;
		params->light_vector = vect_sub(light->position, ray->intersection);
		ray_normalize(&params->light_vector);
		ray_normalize(&params->current_normal);
		angle = dot_product(params->current_normal, params->light_vector);
		if (angle < 0)
			angle = 0;
		lightning += (DIFFUSE_LIGHT * angle) + \
					get_specular(params->current_normal, ray, params);
		light = light->next;
	}
	return (lightning);
}

char	*get_item(int obj_item)
{
	char	*output;

	output = "";
	if (obj_item == 1)
		output = "SPHERE";
	if (obj_item == 2)
		output = "PLANE";
	if (obj_item == 3)
		output = "CYLINDER";
	if (obj_item == 4)
		output = "CONE";
	if (obj_item == 5)
		output = "LIGHT";
	return (output);
}

void	check_shadow(t_params *params, int *index_light, t_vect *i, t_ray *ray)
{
	t_vect	light_pos;

	light_pos = params->light[*index_light].position;
	ray->origin = *i;
	ray->direction = vect_sub(light_pos, *i);
	params->distance_to_light = get_length(&ray->direction);
	ray_normalize(&ray->direction);
}

int		is_shadowed(t_vect intersection, t_params *params, t_object *obj)
{
	t_object	*current_obj;
	t_ray		ray;

	current_obj = params->objects;
	while (current_obj)
	{
		if (current_obj->id != obj->id && current_obj->item != LIGHT)
		{
			params->index_light = -1;
			while (++params->index_light < params->nb_lights)
			{
				check_shadow(params, &params->index_light, &intersection, &ray);
				params->saved_normal = params->current_normal;
				if (intersect(&ray, current_obj, params))
				{
					params->current_normal = params->saved_normal;
					if ((ray.t >= 0) && (ray.t < params->distance_to_light))
						return (IS_SHADOWED);
				}
				params->current_normal = params->saved_normal;
			}
		}
		current_obj = current_obj->next;
	}
	return (NO_SHADOW);
}
