/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 06:05:02 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/02/10 06:10:30 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int	get_nb_objects(t_params *params)
{
	int	nb_objects;

	params->nb_objects = 0; /* Operation temporaire*/
	nb_objects = NB_OBJECTS;
	return (nb_objects);
}
