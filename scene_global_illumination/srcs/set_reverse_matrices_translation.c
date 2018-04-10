/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_reverse_matrices_translation.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 22:28:32 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/10 22:35:13 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	set_reverse_translation(t_transform *transforms, double dx, double dy, double dz)
{
	transforms->reverse_translation.mat[0][0] = 1;
	transforms->reverse_translation.mat[0][1] = 0;
	transforms->reverse_translation.mat[0][2] = 0;
	transforms->reverse_translation.mat[0][3] = -dx;
	transforms->reverse_translation.mat[1][0] = 0;
	transforms->reverse_translation.mat[1][1] = 1;
	transforms->reverse_translation.mat[1][2] = 0;
	transforms->reverse_translation.mat[1][3] = -dy;
	transforms->reverse_translation.mat[2][0] = 0;
	transforms->reverse_translation.mat[2][1] = 0;
	transforms->reverse_translation.mat[2][2] = 1;
	transforms->reverse_translation.mat[2][3] = -dz;
	transforms->reverse_translation.mat[3][0] = 0;
	transforms->reverse_translation.mat[3][1] = 0;
	transforms->reverse_translation.mat[3][2] = 0;
	transforms->reverse_translation.mat[3][3] = 1;
}
