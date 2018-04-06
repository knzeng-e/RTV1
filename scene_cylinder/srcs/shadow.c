/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 08:30:37 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/03/31 23:45:34 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

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

int		is_shadowed(t_vect intersection, t_params *params, t_object *obj)
{
	int			index_light;
	t_ray		shadow_ray;
	t_object	*current_obj;
	t_vect		saved_normal;
	t_vect		light_pos;

	current_obj = params->objects;
	while (current_obj)
	{
		if (current_obj->id != obj->id && current_obj->item != LIGHT)
		{
			index_light = -1;
			while (++index_light < NB_LIGHTS)
			{
				light_pos = params->light[index_light].position;
				shadow_ray.origin = intersection;
				shadow_ray.direction = vect_sub(light_pos, intersection);
				params->distance_to_light = get_length(&shadow_ray.direction);	
				ray_normalize(&shadow_ray.direction);
				saved_normal = params->current_normal;
				if (intersect(&shadow_ray, current_obj, params))
				{
					params->current_normal = saved_normal;
					if ((shadow_ray.t >= 0) && (shadow_ray.t < params->distance_to_light))
					//if (shadow_ray.t >= 0)
						return (IS_SHADOWED);
				}
				params->current_normal = saved_normal;
			}
		}
		current_obj = current_obj->next;
	}
	return (NO_SHADOW);
}
