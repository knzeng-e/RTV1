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
	if (direction.vect_y != 0)
		return (-origin.vect_y / direction.vect_y);
	return (0);
	/*	double	normal;


		normal = (-origin.vect_y / direction.vect_y);
		return (normal);*/
}

int		plane_intersect(t_ray *ray, t_plane *plane, t_params *params)
{
	double	k;
	double	dot_prod;

	ray_normalize(&ray->direction);
	ray_normalize(&plane->normale);
	dot_prod = dot_product(ray->direction, plane->normale);
	if (dot_prod == 0)
	{
	//	ft_putstr("\n Test NOK");
		return (0);
	}
	k = dot_product(substraction(plane->position, ray->origin), plane->normale) / dot_prod;
	//params->t = dot_product(substraction(plane->position, ray->origin), plane->normale) / dot_prod;
	//params->t = dot_product(substraction(ray->origin, plane->position), plane->normale) / dot_prod;
//	if (params->t >= MAX_DISTANCE || params->t <= 0)
	if (k >= MAX_DISTANCE || k <= 0)
	{
	//ft_putstr("\n Test OK");
		return (0);
	}
	if (k < params->t)
		params->t = k;
	ray->t = k;
	save_intersection(ray);
	return (1);
/*	if (ray->direction.vect_z == 0)
		return (0);
	k = - (ray->origin.vect_y / ray->direction.vect_z);
	params->t = k * dot_product(ray->direction, plane->normale);
	return (1);*/
}

/*int		plane_intersect(t_ray *ray, t_plane *plane, t_params *params)
  {
  double	denom;
  double	result;
  t_vect	delta;

  if (ray->direction.vect_y != 0)
  ray->t = (-ray->origin.vect_y / ray->direction.vect_y);

  denom = dot_product(ray->direction, plane->normale);
  if (fabs(denom) < 1e-6)
  ft_putstr("OutPUT ==> 0");
  return (0);
  delta = substraction(plane->position, ray->origin);
  params->t = dot_product(delta, plane->normale) / denom;
  if (params->t < 0)
  return (0);
  ray->t = params->t;
  save_intersection(ray);
  result = dot_product(delta, plane->normale) / denom;
  return (1);
  }*/

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
