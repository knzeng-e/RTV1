/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:03:10 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/13 23:50:51 by knzeng-e         ###   ########.fr       */
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

    result.vect_x = vect->vect_x * transform->mat[0][0] + vect->vect_y * transform->mat[0][1] + vect->vect_z * transform->mat[0][2] + transform->mat[0][3]; 

	result.vect_y = vect->vect_x * transform->mat[1][0] + vect->vect_y * transform->mat[1][1] + vect->vect_z * transform->mat[1][2] + transform->mat[1][3];

	result.vect_z = vect->vect_x * transform->mat[2][0] + vect->vect_y * transform->mat[2][1] + vect->vect_z * transform->mat[2][2] + transform->mat[2][3];

	result.vect_w = vect->vect_x * transform->mat[3][0] + vect->vect_z * transform->mat[3][1] + vect->vect_z * transform->mat[3][2] + transform->mat[3][3];


	/*result.vect_x = vect->vect_x * transform->mat[0][0] + vect->vect_y * transform->mat[1][0] + vect->vect_z * transform->mat[2][0] + transform->mat[3][0]; 
	result.vect_y = vect->vect_x * transform->mat[0][1] + vect->vect_y * transform->mat[1][1] + vect->vect_z * transform->mat[2][1] + transform->mat[3][1]; 
	result.vect_z = vect->vect_x * transform->mat[0][2] + vect->vect_y * transform->mat[1][2] + vect->vect_z * transform->mat[2][2] + transform->mat[3][2];
	result.vect_w = vect->vect_x * transform->mat[0][3] + vect->vect_z * transform->mat[1][3] + vect->vect_z * transform->mat[2][3] + transform->mat[3][3];*/
	return (result);
}
