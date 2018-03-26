/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:42:53 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/03/26 21:43:37 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	 apply_transform(t_vect *vect, t_params *params)
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
}


int		track_ray(t_params *params)
{
	t_vect		saved_normal;
	t_color		rgb;
	t_object	*obj;
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
	//to = set_vector(0, 0, -100);
//	set_camera_look_at(&ray, params, &from, &to);
	//params->eye.from = set_vector(0, 10, 0);
	print_objects(params->objects);
	//params->eye.to = set_vector(0, 0, -10);
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			set_origin(i, j, &ray, params);
			set_camera(&ray, params, i, j);
			params->current_ray = ray;

		//	rotate_x_axis(&(params->current_ray.direction), params->rotation_val, &params->transforms);
			rotate_y_axis(&(params->current_ray.direction), params->rotation_val, &params->transforms);
		//	rotate_z_axis(&(params->current_ray.direction), params->rotation_val, &params->transforms);


		//	rotate_x_axis(&(params->current_ray.origin), params->rotation_val, &params->transforms);
			rotate_y_axis(&(params->current_ray.origin), params->rotation_val, &params->transforms);
		//	rotate_z_axis(&(params->current_ray.origin), params->rotation_val, &params->transforms);






			//	set_camera_look_at(&ray, params, &params->eye.from, &params->eye.to);
			/*apply_transform(&ray.origin, params);
			  apply_transform(&ray.direction, params);*/
			//from = set_vector(0, 0, -1);
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
					if (!is_shadowed(ray.intersection, params, obj))
						lightning += shading(&ray, params);
					//lightning /= (params->distance_to_light * params->distance_to_light);
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
