/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:36:32 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/11/04 14:11:23 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

t_vect	cross_product(t_vect vect1, t_vect vect2)
{
	t_vect	output_vect;

	/*cx = ay.bz − az.by;
	cy = az.bx − ax.bz;
	cz = ax.by − ay.bx;*/
	output_vect.vect_x = vect1.vect_y * vect2.vect_z - vect1.vect_z * vect2.vect_y;
	output_vect.vect_y = vect1.vect_z * vect2.vect_x - vect1.vect_x * vect2.vect_z;
	output_vect.vect_z = vect1.vect_x * vect2.vect_y - vect1.vect_y * vect2.vect_x;
	return (output_vect);
}
