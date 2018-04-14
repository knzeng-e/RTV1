/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:42:53 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/15 00:35:11 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

/*void	 apply_transform(t_vect *vect, t_params *params)
{
	t_vect4	homogen;

	homogen = set_homogen(vect);
	//vect_matrx_multiply(&homogen, &params->eye.cam_to_world);
	*vect = set_reverse_homogen(&homogen);
	rotate_x_axis(&(params->current_ray.direction), params->rotation_val, &params->transforms);
	rotate_y_axis(&(params->current_ray.direction), params->rotation_val, &params->transforms);
	rotate_z_axis(&(params->current_ray.direction), params->rotation_val, &params->transforms);


	rotate_x_axis(&(params->current_ray.origin), params->rotation_val, &params->transforms);
	rotate_y_axis(&(params->current_ray.origin), params->rotation_val, &params->transforms);
	rotate_z_axis(&(params->current_ray.origin), params->rotation_val, &params->transforms);
}*/


int		track_ray(t_params *params)
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
	int			i;
	int			j;
	int			cpt;
	int			cpt_light;

	t_min = MAX_DISTANCE;
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			//ray.origin = params->eye.from;
			set_camera(&ray, params, i, j);
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
					cpt_light = -1;
					lightning = AMBIANT_LIGHT;
					saved_normal = params->current_normal;
                    t_min_saved = params->t_min_saved;
                    t_max_saved = params->t_max_saved;
					if (!is_shadowed(ray.intersection, params, obj))
						lightning += shading(&ray, params);
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
