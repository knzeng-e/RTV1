/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:42:53 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/11/25 03:44:33 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	draw_pixel(t_params *params, int i, int j, int color)
{
	params->img_data[j  * WIDTH + i] = color;
	//mlx_pixel_put(params->mlx, params->win, i, j, color);
}

double	radians(double angle)
{
	return (angle * M_PI / 180);
}

int	track_ray(t_params *params)
{
	t_ray	*ray;
	t_vect	p_camera_space;
	t_vect	origin;
	double	pix_norm_x;
	double	pix_norm_y;
	double	image_aspect_ratio;
	double	pix_remap_x;
	double	pix_remap_y;
	double	pix_camera_x;
	double	pix_camera_y;
	double	t_min;
	int		sphere_hit;
	int		color;
	int		hit;
	int		i;
	int		j;
	int		cpt;

	t_min = MAX_DISTANCE;
	origin = set_vector(0, 0, 0);
	i = 0;
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

			pix_norm_x = (i + 0.5) / WIDTH; //Normalize Pix_dimension to [0;1]
			pix_norm_y = (j + 0.5) / HEIGHT;
			image_aspect_ratio = WIDTH/ HEIGHT;
			pix_remap_x = (2 * pix_norm_x - 1) * image_aspect_ratio;
			pix_remap_y = 1 - 2 * pix_norm_y;
			pix_camera_x = pix_remap_x * tan(radians(30) / 2); // FOV 30 degrees
			pix_camera_y = pix_remap_y * tan(radians(30) / 2);
			p_camera_space = set_vector(pix_camera_x, pix_camera_y, -1);
			ray->direction = vect_sub(p_camera_space, origin);
			//ray->direction = vect_sub(p_camera_space, ray->origin);
			ray_normalize(&ray->direction);

			cpt = -1;
			sphere_hit = -1;
			t_min = MAX_DISTANCE;
			while (++cpt < NB_SPHERES)
			{
				hit = sphere_intersect(ray, params->sphere_list[cpt], params);
				if (hit && ray->t < t_min)
				{
					t_min = ray->t;
					sphere_hit = cpt;
					color = params->sphere_list[cpt].color;
				}
				if (sphere_hit != -1)
					draw_pixel(params, i, j, color);
				//	draw_pixel(params, i, j, ((cpt == 0) ? 0x000000FF : ((cpt == 1) ? 0x00FFFF00 : 0x0000FF00)));
			}
			if (plane_intersect(ray, (params->plane), params))
				draw_pixel(params, i, j, 0x004E1609);
			/*else
			  draw_pixel(params, i, j, 0x00CECECE);*/
			j++;
		}
		i++;
	}
	return (0);
}
