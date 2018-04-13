/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_reverse_matrices_translations.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:39:36 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/11 16:42:05 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	set_reverse_translation(t_transform *transforms, double dx, double dy, double dz)
{
	transforms->translation.mat[0][0] = 1;
	transforms->translation.mat[0][1] = 0;
	transforms->translation.mat[0][2] = 0;
	transforms->translation.mat[0][3] = -dx;
	transforms->translation.mat[1][0] = 0;
	transforms->translation.mat[1][1] = 1;
	transforms->translation.mat[1][2] = 0;
	transforms->translation.mat[1][3] = -dy;
	transforms->translation.mat[2][0] = 0;
	transforms->translation.mat[2][1] = 0;
	transforms->translation.mat[2][2] = 1;
	transforms->translation.mat[2][3] = -dz;
	transforms->translation.mat[3][0] = 0;
	transforms->translation.mat[3][1] = 0;
	transforms->translation.mat[3][2] = 0;
	transforms->translation.mat[3][3] = 1;
}
