/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_reverse_matrices_reverse_rotations.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 20:41:39 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/10 21:51:30 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	set_reverse_x_reverse_rotation(t_transform *transforms)
{
	double	angle;

	angle = transforms->angle_rotation;
	transforms->x_reverse_rotation.mat[0][0] = 1;
	transforms->x_reverse_rotation.mat[0][1] = 0;
	transforms->x_reverse_rotation.mat[0][2] = 0;
	transforms->x_reverse_rotation.mat[0][3] = 0;
	transforms->x_reverse_rotation.mat[1][0] = 0;
	transforms->x_reverse_rotation.mat[1][1] = cos(angle);
	transforms->x_reverse_rotation.mat[1][2] = sin(angle);
	transforms->x_reverse_rotation.mat[1][3] = 0;
	transforms->x_reverse_rotation.mat[2][0] = 0;
	transforms->x_reverse_rotation.mat[2][1] = -sin(angle);
	transforms->x_reverse_rotation.mat[2][2] = cos(angle);
	transforms->x_reverse_rotation.mat[2][3] = 0;
	transforms->x_reverse_rotation.mat[3][0] = 0;
	transforms->x_reverse_rotation.mat[3][1] = 0;
	transforms->x_reverse_rotation.mat[3][2] = 0;
	transforms->x_reverse_rotation.mat[3][3] = 1;
}

void	set_reverse_y_reverse_rotation(t_transform *transforms)
{
	double	angle;

	angle = transforms->angle_rotation;
	transforms->y_reverse_rotation.mat[0][0] = cos(angle);
	transforms->y_reverse_rotation.mat[0][1] = 0;
	transforms->y_reverse_rotation.mat[0][2] = -sin(angle);
	transforms->y_reverse_rotation.mat[0][3] = 0;
	transforms->y_reverse_rotation.mat[1][0] = 0;
	transforms->y_reverse_rotation.mat[1][1] = 1;
	transforms->y_reverse_rotation.mat[1][2] = 0;
	transforms->y_reverse_rotation.mat[1][3] = 0;
	transforms->y_reverse_rotation.mat[2][0] = sin(angle);
	transforms->y_reverse_rotation.mat[2][1] = 0;
	transforms->y_reverse_rotation.mat[2][2] = cos(angle);
	transforms->y_reverse_rotation.mat[2][3] = 0;
	transforms->y_reverse_rotation.mat[3][0] = 0;
	transforms->y_reverse_rotation.mat[3][1] = 0;
	transforms->y_reverse_rotation.mat[3][2] = 0;
	transforms->y_reverse_rotation.mat[3][3] = 1;
}

void	set_reverse_z_reverse_rotation(t_transform *transforms)
{
	double	angle;

	angle = transforms->angle_rotation;
	transforms->z_reverse_rotation.mat[0][0] = cos(angle);
	transforms->z_reverse_rotation.mat[0][1] = sin(angle);
	transforms->z_reverse_rotation.mat[0][2] = 0;
	transforms->z_reverse_rotation.mat[0][3] = 0;
	transforms->z_reverse_rotation.mat[1][0] = -sin(angle);
	transforms->z_reverse_rotation.mat[1][1] = cos(angle);
	transforms->z_reverse_rotation.mat[1][2] = 0;
	transforms->z_reverse_rotation.mat[1][3] = 0;
	transforms->z_reverse_rotation.mat[2][0] = 0;
	transforms->z_reverse_rotation.mat[2][1] = 0;
	transforms->z_reverse_rotation.mat[2][2] = 1;
	transforms->z_reverse_rotation.mat[2][3] = 0;
	transforms->z_reverse_rotation.mat[3][0] = 0;
	transforms->z_reverse_rotation.mat[3][1] = 0;
	transforms->z_reverse_rotation.mat[3][2] = 0;
	transforms->z_reverse_rotation.mat[3][3] = 1;
}
