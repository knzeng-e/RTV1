/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 04:12:55 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/02/18 12:23:13 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

double	shading(t_ray *ray, t_params *params)
{
	t_object	*light;
	t_vect		light_vector;
	double		angle;
	double		lightning;

	lightning = 0;
	light = params->objects;
	while (light->item != LIGHT)
		light = light->next;
	while (light && light->item == LIGHT)
	{
		params->current_light.intensity = light->specular;
		light_vector = vect_sub(light->position, ray->intersection);
		params->light_vector = light_vector;
		ray_normalize(&light_vector);
		angle = dot_product(params->current_normal, light_vector);
		if (angle <= 0)
			angle = 0;
		lightning += (DIFFUSE_LIGHT * angle) + get_specular(params->current_normal, ray, params);
		light = light->next;
	}
	return (lightning);
}
