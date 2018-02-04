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

void	save_intersection(t_ray *ray)
{
	double	x_intersect;
	double	y_intersect;
	double	z_intersect;

	/*ray = O + DIR * t*/;
	x_intersect = ray->origin.vect_x + ray->direction.vect_x * ray->t;
	y_intersect = ray->origin.vect_y + ray->direction.vect_y * ray->t;
	z_intersect = ray->origin.vect_z + ray->direction.vect_z * ray->t;
	ray->intersection = set_vector(x_intersect, y_intersect, z_intersect);
}

t_vect	get_normal(t_vect intersection, t_sphere sphere)
{
	t_vect	depth;

	depth = vect_sub(intersection, sphere.center);
	return (vect_divide(depth, sphere.rayon));
}

 int	sphere_intersect(t_ray *ray, t_sphere sphere, t_params *params)
{
	t_vect	L;
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
	return (1);
	/*get normal*/
}
