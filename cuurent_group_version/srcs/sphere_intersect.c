/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:39:28 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/16 04:02:42 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

t_vect	get_normal(t_vect intersection, t_sphere sphere)
{
	t_vect	depth;

	depth = vect_sub(intersection, sphere.center);
	return (vect_divide(depth, sphere.rayon));
}

int		sphere_intersect(t_ray *ray, t_sphere sphere, t_params *params)
{
	t_vect	light;
	double	tca;
	double	thc;
	double	s2;
	double	t0;

	light = vect_sub(sphere.center, ray->origin);
	tca = dot_product(light, ray->direction);
	if (tca < 0)
		return (0);
	s2 = dot_product(light, light) - (tca * tca);
	if (sqrt(s2) > sphere.rayon)
		return (0);
	thc = sqrt((sphere.rayon * sphere.rayon) - s2);
	t0 = tca - thc;
	ray->t = t0;
	params->ray_depth = ray->t;
	save_intersection(ray);
	params->current_normal = vect_divide(vect_sub(ray->intersection\
				, sphere.center), sphere.rayon);
	return (1);
}
