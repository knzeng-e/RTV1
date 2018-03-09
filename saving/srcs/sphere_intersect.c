/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:39:28 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/11/05 18:28:50 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

t_vect	get_normal(t_vect intersection, t_sphere sphere)
{
	t_vect	depth;

	depth = vect_sub(intersection, sphere.center);
	return (vect_divide(depth, sphere.rayon));
}

int	sphere_intersect(t_ray *ray, t_sphere sphere, t_params *params)
{
	t_vect	L;
	t_vect	depth;
	double	tca;
	double	thc;
	double	s2;
	double	s;
	double	t0;

	L = vect_sub(sphere.center, ray->origin);
	tca = dot_product(L, ray->direction);
	if (tca < 0)
		return (0);
	s2 = dot_product(L, L) - (tca * tca);
	s = sqrt(s2);
	if (s > sphere.rayon)
		return (0);
	thc = sqrt((sphere.rayon * sphere.rayon) - s2);
	t0 = tca - thc;
	ray->t = t0;
	params->ray_depth = ray->t;
	save_intersection(ray);
	depth = vect_sub(ray->intersection, sphere.center);
	params->current_normal = vect_divide(depth, sphere.rayon);
	return (1);
}

/*int		sphere_intersect(t_ray *ray, t_sphere sphere, t_params *params)
{
	t_vect	depth;
	double	b;
	double	c;
	double	t0;
	double	t1;
	double	disc;

	depth = vect_sub(ray->origin, sphere.center);
    b = 2 * dot_product(depth, ray->direction);
    c = dot_product(depth, depth) - (sphere.rayon * sphere.rayon);
    disc = b * b - 4 * c;
    if (disc < 0)
		return (0);
    disc = sqrt(disc) / 2;
    //disc = sqrt(disc);
    t0 = -b - disc;
    t1 = -b + disc;
    ray->t = (t0 < t1) ? t0 : t1;
	params->ray_depth = ray->t;
	save_intersection(ray);
	depth = vect_sub(ray->intersection, sphere.center);
	params->current_normal = vect_divide(depth, sphere.rayon);
    return (1);
}*/
