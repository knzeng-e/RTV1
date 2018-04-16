/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 03:22:38 by neprocur          #+#    #+#             */
/*   Updated: 2018/04/16 08:46:19 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

t_matrix		matrix_multiply(t_matrix *mat1, t_matrix *mat2)
{
	t_matrix	result;
	int			i;
	int			j;
	int			k;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
				result.mat[i][j] += mat1->mat[i][k] * mat2->mat[k][j];
		}
	}
	return (result);
}

t_vect4			vect_matrx_multiply(t_vect4 *vect, t_matrix *transform)
{
	t_vect4	result;

	result.vect_x = vect->vect_x * transform->mat[0][0] + vect->vect_y *\
		transform->mat[1][0] + vect->vect_z * transform->mat[2][0] +\
		transform->mat[3][0];
	result.vect_y = vect->vect_x * transform->mat[0][1] + vect->vect_y *\
		transform->mat[1][1] + vect->vect_z * transform->mat[2][1] +\
		transform->mat[3][1];
	result.vect_z = vect->vect_x * transform->mat[0][2] + vect->vect_y *\
		transform->mat[1][2] + vect->vect_z * transform->mat[2][2] +\
		transform->mat[3][2];
	result.vect_w = vect->vect_x * transform->mat[0][3] + vect->vect_z *\
		transform->mat[1][3] + vect->vect_z * transform->mat[2][3] +\
		transform->mat[3][3];
	return (result);
}

void            rotate_cone(t_cone *cone, t_vect rotation, t_params *params)
{
    rotate_x_axis(&cone->axe, rotation.vect_x, &params->transforms, 0);
    rotate_y_axis(&cone->axe, rotation.vect_y, &params->transforms, 0);
    rotate_z_axis(&cone->axe, rotation.vect_z, &params->transforms, 0);
}

void            rotate_cylinder(t_cylinder *cylinder, t_vect rotation, \
    t_params *params)
{
    rotate_x_axis(&cylinder->axe, rotation.vect_x, &params->transforms, 0);
    rotate_y_axis(&cylinder->axe, rotation.vect_y, &params->transforms, 0);
    rotate_z_axis(&cylinder->axe, rotation.vect_z, &params->transforms, 0);
}

void            rotate_plane(t_plane *plane, t_vect rotation, t_params *params)
{
    rotate_x_axis(&plane->normale, rotation.vect_x, &params->transforms, 0);
    rotate_y_axis(&plane->normale, rotation.vect_y, &params->transforms, 0);
    rotate_z_axis(&plane->normale, rotation.vect_z, &params->transforms, 0);
}
