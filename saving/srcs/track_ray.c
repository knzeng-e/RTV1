/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:42:53 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/03/09 23:03:36 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

double	lightning(t_params *params, t_ray *ray, int sphere_hit)
{
	t_vect	light_vector;
	double	diffuse;
	//t_vect	specular;
	double		angle;
	double		length;
	double		normal_length;

	light_vector = vect_sub(params->light[0].position, ray->intersection);
	length = get_length(&light_vector);
	ray_normalize(&light_vector);
	params->current_normal = vect_sub(ray->intersection, params->sphere_list[sphere_hit].center);
	normal_length = get_length(&params->current_normal);
	params->current_normal = vect_divide(params->current_normal, normal_length);
	ray_normalize(&params->current_normal);
	angle = dot_product(light_vector, params->current_normal);
	if (angle > 0)
		diffuse = angle / (length * normal_length);
	else
		diffuse = 0;
	return (diffuse);
}

int	track_ray(t_params *params)
{
	//t_ray		*ray;
	t_vect		saved_normal;
//	t_vect		from;
//	t_vect		to;
	t_color		rgb;
	t_object	*obj;
	t_object	*light;
	t_ray		ray;
	double		t_min;
	double		lightning;
	int			sphere_hit;
	int			hit;
	int			i;
	int			j;
	int			cpt;
	int			cpt_light;

	t_min = MAX_DISTANCE;
	i = 0;
//	from = set_vector(0, 0, 0);
	print_objects(params->objects);
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			set_origin(i, j, &ray, params);
			//set_camera_look_at(ray, params, &from, &to);
			set_camera(&ray, params, i, j);
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
					light = params->objects;
					cpt_light = -1;
					lightning = AMBIANT_LIGHT;
					saved_normal = params->current_normal;
					if (!is_shadowed(ray.intersection, params, obj))
					{						
						params->current_normal = saved_normal;
						ray_normalize(&params->current_normal);
						lightning += shading(&ray, params);
					}
					params->color = get_color(obj->color) * lightning;
					rgb = obj->color;
					params->color = rgb_to_int(rgb.red * lightning, rgb.green * lightning, rgb.blue * lightning);
					draw_pixel(params, i, j, params->color);
				}
				obj = obj->next;
				cpt++;
			}
			j++;
		}
		i++;
	}
	return (0);
}
