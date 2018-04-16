/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_coords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 03:10:41 by neprocur          #+#    #+#             */
/*   Updated: 2018/04/16 07:45:28 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	save_intersection(t_ray *ray)
{
	double	x_intersect;
	double	y_intersect;
	double	z_intersect;

	x_intersect = ray->origin.vect_x + ray->direction.vect_x * ray->t;
	y_intersect = ray->origin.vect_y + ray->direction.vect_y * ray->t;
	z_intersect = ray->origin.vect_z + ray->direction.vect_z * ray->t;
	ray->intersection = set_vector(x_intersect, y_intersect, z_intersect);
	if ((ray->t_min == ray->t_max) || \
			(y_intersect > ray->t_min && y_intersect < ray->t_max))
		ray->is_inter = 1;
	else
		ray->is_inter = 0;
}

void	save_sphere_coord(t_params *params, char *infos, int *nb_coord)
{
	int	current;

	current = params->current_sphere_index;
	if (*nb_coord == 0)
		params->sphere_list[current].center.vect_x = ft_atoi(infos);
	if (*nb_coord == 1)
		params->sphere_list[current].center.vect_y = ft_atoi(infos);
	if (*nb_coord == 2)
		params->sphere_list[current].center.vect_z = ft_atoi(infos);
}
