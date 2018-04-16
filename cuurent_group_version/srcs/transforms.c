/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:11:09 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/16 00:58:46 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

t_vect	set_reverse_homogen(t_vect4 *vect)
{
	t_vect	result;

	if (vect->vect_w != 0)
	{
		result.vect_x = vect->vect_x / vect->vect_w;
		result.vect_y = vect->vect_y / vect->vect_w;
		result.vect_z = vect->vect_z / vect->vect_w;
	}
	else
		result = set_vector(vect->vect_x, vect->vect_y, vect->vect_z);
	return (result);
}

t_vect4	set_homogen(t_vect *vect, int is_point)
{
	t_vect4	result;

	result.vect_x = vect->vect_x;
	result.vect_y = vect->vect_y;
	result.vect_z = vect->vect_z;
	result.vect_w = is_point;
	return (result);
}

t_vect	rotate_x_axis(t_vect *vect, double angle, t_transform *transform, \
		int is_point)
{
	t_vect4	result;
	t_vect4	homogen_vect;

	transform->angle_rotation = radians(angle);
	set_x_rotation(transform);
	homogen_vect = set_homogen(vect, is_point);
	result = vect_matrx_multiply(&homogen_vect, &transform->x_rotation);
	*vect = set_reverse_homogen(&result);
	return (*vect);
}

t_vect	rotate_y_axis(t_vect *vect, double angle, t_transform *transform, \
		int is_point)
{
	t_vect4	result;
	t_vect4	homogen_vect;

	transform->angle_rotation = radians(angle);
	set_y_rotation(transform);
	homogen_vect = set_homogen(vect, is_point);
	result = vect_matrx_multiply(&homogen_vect, &transform->y_rotation);
	*vect = set_reverse_homogen(&result);
	return (*vect);
}

t_vect	rotate_z_axis(t_vect *vect, double angle, t_transform *transform, \
		int is_point)
{
	t_vect4	result;
	t_vect4	homogen_vect;

	transform->angle_rotation = radians(angle);
	set_z_rotation(transform);
	homogen_vect = set_homogen(vect, is_point);
	result = vect_matrx_multiply(&homogen_vect, &transform->z_rotation);
	*vect = set_reverse_homogen(&result);
	return (*vect);
}
