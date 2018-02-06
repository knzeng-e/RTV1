/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:42:53 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/02/06 11:59:44 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	draw_pixel(t_params *params, int i, int j, int color)
{
	params->img_data[j  * WIDTH + i] = color;
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
	double	angle;
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
		diffuse = params->light[0].intensity * angle / (length * normal_length);
	else
		diffuse = 0;
	//if (angle < 0)
	//	angle = 0;
	//if (angle)
	//printf("\n Color of sphere %d (diffuse == %f) ==> %f", sphere_hit, diffuse, params->sphere_list[sphere_hit].color * diffuse);
	//params->sphere_list[sphere_hit].color = couleur(params->sphere_list[sphere_hit].color);
	//	params->sphere_list[sphere_hit].color  += diffuse;
	//draw_pixel(params, i, j, (get_color(params->sphere3.color)  + 0x000000FF * angle) * 0.5);
	//draw_pixel(params, i, j, params->sphere_list[cpt].color);
	//}
	//}
	return (diffuse);
}


int	track_ray(t_params *params)
{
	t_ray	*ray;
	double	t_min;
	int		sphere_hit;
	//int		color;
	int		hit;
	int		i;
	int		j;
	int		cpt;

	t_min = MAX_DISTANCE;
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
			set_camera(ray, params, i, j);
			cpt = -1;
			sphere_hit = -1;
			t_min = MAX_DISTANCE;
			while (++cpt < NB_SPHERES)
			{
				if (plane_intersect(ray, (params->plane), params))
					draw_pixel(params, i, j, 0x004E1609);
				hit = sphere_intersect(ray, params->sphere_list[cpt], params);
				if (hit && ray->t < t_min)
				{
					t_min = ray->t;
					sphere_hit = cpt;
					//params->color =  params->sphere_list[cpt].color;
				}
				if (sphere_hit != -1)
				{
					params->color =  params->sphere_list[sphere_hit].color;
					params->color *= couleur(lightning(params, ray, sphere_hit) + AMBIANT_LIGHT);
					draw_pixel(params, i, j, params->color);
				}
				/*else
				  draw_pixel(params, i, j, RGB(242, 242, 242));*/
			}
			/*else
			  draw_pixel(params, i, j, 0x00CECECE);*/
			j++;
		}
		i++;
	}
	return (0);
}
