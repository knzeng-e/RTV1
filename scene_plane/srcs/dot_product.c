/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:07:51 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/11/04 14:12:49 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

double	dot_product(t_vect vect1, t_vect vect2)
{
	double	dot_prod;

	dot_prod = vect1.vect_x * vect2.vect_x + vect1.vect_y * vect2.vect_y + vect1.vect_z * vect2.vect_z;
	return (dot_prod);
}
