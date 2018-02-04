/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 22:08:16 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/11/25 02:58:53 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

double	plane_normal(t_vect origin, t_vect direction)
{
	/**/
	double	normal;


	normal = (-origin.vect_y / direction.vect_y);
	return (normal);
}

int		plane_intersect(t_ray *ray, t_plane *plane, t_params *params)
{
	double	angle;
	double	result;
	//t_vect	delta;

	angle = dot_product(ray->direction, plane->normale);
	if (fabs(angle) < 1e-6)
		return (0);
	plane->distance = vect_sub(plane->position, ray->origin);
	/*delta.vect_x = plane->position.vect_x - ray->origin.vect_x;
	delta.vect_y = plane->position.vect_y - ray->origin.vect_y;
	delta.vect_z = plane->position.vect_z - ray->origin.vect_z;
	result = dot_product(delta, plane->normale) / angle;*/
	result = dot_product(plane->distance, plane->normale) / angle;
	params->t = result;
	return (result >= 0);
}

/*double	plane_intersect(t_vect origin, t_vect direction)
{
	double d;
	t_vect	p;
	t_vect	temp;

	t_vect	pos;
	t_vect	dir;
	t_vect	pos2;
	t_vect	dir2;
	r->getOrigin(pos);
	r->getDirection(dir);
	trans->doInvTransformation(pos2,pos);
	trans->doInvTransformation(dir2,dir);

	double t;

	if (direction.vect_x != 0)
	{
		t = -pos2[0] / dir2[0];
		if (t > epsilon)
		{
			p[0] = 0.0;
			p[1] = pos2[1] + dir2[1] * t;
			p[2] = pos2[2] + dir2[2] * t;
			p[3] = 1.0;

			d = distance (p, pos2);

			trans->doTransformation(i,p);

			return d;
		}
		else
			return MAXDOUBLE;
	}
	else
		return MAXDOUBLE;
}
}
}*/
