/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 23:43:27 by neprocur          #+#    #+#             */
/*   Updated: 2018/04/16 08:03:49 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

t_vect	vect_sub(t_vect vect1, t_vect vect2)
{
	t_vect	result;

	result.vect_x = vect1.vect_x - vect2.vect_x;
	result.vect_y = vect1.vect_y - vect2.vect_y;
	result.vect_z = vect1.vect_z - vect2.vect_z;
	return (result);
}

t_vect	vect_add(t_vect vect1, t_vect vect2)
{
	t_vect	result;

	result.vect_x = vect1.vect_x + vect2.vect_x;
	result.vect_y = vect1.vect_y + vect2.vect_y;
	result.vect_z = vect1.vect_z + vect2.vect_z;
	return (result);
}
