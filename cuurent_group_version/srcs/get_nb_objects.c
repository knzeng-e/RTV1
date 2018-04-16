/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 06:05:02 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/16 03:45:24 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int	get_nb_objects(t_params *params)
{
	return (params->nb_lights + params->nb_planes + params->nb_cones + \
			params->nb_cylinders + params->nb_spheres);
}
