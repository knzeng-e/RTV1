/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 23:41:09 by neprocur          #+#    #+#             */
/*   Updated: 2018/04/15 23:42:07 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

t_vect	addition(t_vect vect1, t_vect vect2)
{
	t_vect	result;

	result.vect_x = vect1.vect_x + vect2.vect_x;
	result.vect_y = vect1.vect_y + vect2.vect_y;
	result.vect_z = vect1.vect_z + vect2.vect_z;
	return (result);
}

t_vect	substraction(t_vect vect1, t_vect vect2)
{
	t_vect	result;

	result.vect_x = vect1.vect_x - vect2.vect_x;
	result.vect_y = vect1.vect_y - vect2.vect_y;
	result.vect_z = vect1.vect_z - vect2.vect_z;
	return (result);
}

t_vect	vect_multiply(t_vect vect, double cste)
{
	t_vect	result;

	result.vect_x = vect.vect_x * cste;
	result.vect_y = vect.vect_y * cste;
	result.vect_z = vect.vect_z * cste;
	return (result);
}

t_vect	vect_divide(t_vect vect, double cste)
{
	t_vect	result;

	result.vect_x = vect.vect_x / cste;
	result.vect_y = vect.vect_y / cste;
	result.vect_z = vect.vect_z / cste;
	return (result);
}

void	init_transform_matrices(t_transform *transforms)
{
	double	angle;

	transforms = (t_transform *)malloc(sizeof(t_transform));
	if (transforms == NULL)
		exit(MALLOC_TRANSFORM_ERROR);
	angle = 30;
	set_x_rotation(transforms);
	set_y_rotation(transforms);
	set_z_rotation(transforms);
}
