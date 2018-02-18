/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:42:53 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/02/18 12:05:14 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	draw_pixel(t_params *params, int i, int j, int color)
{
	int				cpt;
	unsigned int	p;

	cpt = 0;
	p = i * (params->bpp / 8) + j * (params->size_line);
	while (cpt < (params->bpp / 8))
	{
		params->img_data[p + cpt] = color;
		color >>= 8;
		cpt++;
	}
	//	params->img_data[j * params->size_line + i * params->bpp] = color;
}

double	radians(double angle)
{
	return (angle * M_PI / 180);
}

double	max(double nbre1, double nbre2)
{
	double	output;

	output = (nbre1 > nbre2) ? nbre1 : nbre2;
	return (output);
}

void	set_camera(t_ray *ray, t_params *params, int i, int j)
{
	t_vect	p_camera_space;
	double	pix_norm_x;
	double	pix_norm_y;
	double	image_aspect_ratio;
	double	pix_remap_x;
	double	pix_remap_y;
	double	pix_camera_x;
	double	pix_camera_y;

	pix_norm_x = (i + 0.5) / WIDTH; //Normalize Pix_dimension to [0;1]
	pix_norm_y = (j + 0.5) / HEIGHT;
	image_aspect_ratio = WIDTH/ HEIGHT;
	pix_remap_x = (2 * pix_norm_x - 1) * image_aspect_ratio;
	pix_remap_y = 1 - 2 * pix_norm_y;
	pix_camera_x = pix_remap_x * tan(radians(params->fov) / 2); // FOV 30 degrees
	pix_camera_y = pix_remap_y * tan(radians(params->fov) / 2);
	p_camera_space = set_vector(pix_camera_x, pix_camera_y, -1);
	ray->direction = vect_sub(p_camera_space, ray->origin);
	ray_normalize(&ray->direction);
}

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
	t_ray		*ray;
	t_vect		saved_normal;
	t_color		rgb;
	t_object	*obj;
	t_object	*light;
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
	print_objects(params->objects);
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			ray = (t_ray *)malloc(sizeof(t_ray));
			if (ray == NULL)
				return (ft_free(params));
			params->rays_to_free++;
			set_origin(i, j, ray, params);
			set_camera(ray, params, i, j);
			cpt = 0;
			t_min = MAX_DISTANCE;
			obj = params->objects;
			while (cpt < 6 && obj)
			{
				sphere_hit = -1;
				hit = intersect(ray, obj, params);
				if (hit && ray->t < t_min)
				{
					t_min = ray->t;
					sphere_hit = cpt;
				}
				if (sphere_hit != -1)
				{
					params->current_obj = *obj;
					light = params->objects;
					cpt_light = -1;
					lightning = AMBIANT_LIGHT;
					saved_normal = params->current_normal;
					if (!is_shadowed(ray->intersection, params, obj))
					{						
						params->current_normal = saved_normal;
						ray_normalize(&params->current_normal);
						lightning += shading(ray, params);
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
