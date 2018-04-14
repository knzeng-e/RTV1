/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 20:43:48 by neprocur          #+#    #+#             */
/*   Updated: 2018/04/04 20:43:51 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

double	get_length(t_vect *vect)
{
	double	module;

	module = 0;
	module += vect->vect_x * vect->vect_x;
	module += vect->vect_y * vect->vect_y;
	module += vect->vect_z * vect->vect_z;
	return (sqrt(module));
}
