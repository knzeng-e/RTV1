/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 08:01:56 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/02/18 00:25:51 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

double	get_specular(t_vect normal, t_ray *ray, t_params *params)
{
	double	specular;
	double	angle;
	t_vect	reflected_ray;
	t_vect	viewing_vector;

	/*
	 *  R = 2*N*dot(N, L) - L
	 *  r_dot_v = dot(R, V)
	 *  if r_dot_v > 0
	 *  i += light.intensity*pow(r_dot_v/(length(R)*length(V)), s)
	 * */
	specular = 0;
	viewing_vector = vect_multiply(ray->direction, -1);
	 /*  R = 2*N*dot(N, L) - L */
	reflected_ray = vect_sub(vect_multiply(normal, (2 * dot_product(normal, params->light_vector))), params->light_vector);
	angle = dot_product(reflected_ray, viewing_vector);
	if (angle > 0)
		specular = SPECULAR * pow(angle / get_length(&reflected_ray) * get_length(&viewing_vector), params->specularity);
	return (specular);
}
