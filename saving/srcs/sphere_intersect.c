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

/*t_vect	get_sphere_normale()
{

}*/

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
	return (1);
	/*get normal*/
}
