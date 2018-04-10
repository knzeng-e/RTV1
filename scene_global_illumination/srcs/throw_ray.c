/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 13:37:56 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/10 14:17:15 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int throw_ray(t_params *params, int *i, int *j)
{
	t_vect		saved_normal;
	t_color		rgb;
	t_object	*obj;
	t_ray		ray;
	double		t_min;
	double		t_min_saved;
	double		t_max_saved;
	double		lightning;
	int			sphere_hit;
	int			hit;
	int			cpt;
//	int			cpt_light;

    ray.origin = params->eye.from;
    set_camera(&ray, params, *i, *j);
    params->current_ray = ray;
    cpt = 0;
    t_min = MAX_DISTANCE;
    obj = params->objects;
    while (cpt < NB_ACTIVE_OBJ && obj)
    {
        sphere_hit = -1;
        hit = intersect(&ray, obj, params);
        if (hit && ray.t < t_min)
        {
            t_min = ray.t;
            sphere_hit = cpt;
        }
        if (sphere_hit != -1)
        {
            params->current_obj = *obj;
            //cpt_light = -1;
            lightning = AMBIANT_LIGHT;
            saved_normal = params->current_normal;
            t_min_saved = params->t_min_saved;
            t_max_saved = params->t_max_saved;
            if (!is_shadowed(ray.intersection, params, obj))
                lightning += shading(&ray, params);
            rgb = obj->color;
            params->color = rgb_to_int(rgb.red * lightning, rgb.green * lightning, rgb.blue * lightning);
            draw_pixel(params, *i, *j, params->color);
        }
        obj = obj->next;
        cpt++;
    }
    return (params->current_obj.id);
}
