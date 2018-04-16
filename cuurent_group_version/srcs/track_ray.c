/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:42:53 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/16 07:57:27 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	ray_normalize(t_vect *vect)
{
	double	module;

	module = get_length(vect);
	vect->vect_x /= module;
	vect->vect_y /= module;
	vect->vect_z /= module;
}

void	compute_color(t_params *params, double *lightning)
{
	t_color		rgb;

	rgb = params->obj->color;
	params->color = rgb_to_int(rgb.red * *lightning, rgb.green * *lightning, \
			rgb.blue * *lightning);
	draw_pixel(params, params->i, params->j, params->color);
}

void	throw_ray(t_params *params)
{
	double		lightning;

	params->t_min = MAX_DISTANCE;
	set_camera(&params->ray, params, params->i, params->j);
	params->cpt = -1;
	params->obj = params->objects;
	while (++params->cpt < NB_ACTIVE_OBJ && params->obj)
	{
		params->sphere_hit = -1;
		params->hit = intersect(&params->ray, params->obj, params);
		if (params->hit && params->ray.t < params->t_min)
		{
			params->t_min = params->ray.t;
			params->sphere_hit = params->cpt;
		}
		if (params->sphere_hit != -1)
		{
			params->current_obj = *params->obj;
			lightning = AMBIANT_LIGHT;
			if (!is_shadowed(params->ray.intersection, params, params->obj))
				lightning += shading(&params->ray, params);
			compute_color(params, &lightning);
		}
		params->obj = params->obj->next;
	}
}

int		track_ray(t_params *params)
{
	params->i = 0;
	while (params->i < WIDTH)
	{
		params->j = -1;
		while (++params->j < HEIGHT)
			throw_ray(params);
		params->i++;
	}
	return (0);
}
