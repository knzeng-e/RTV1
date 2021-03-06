/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 03:44:41 by neprocur          #+#    #+#             */
/*   Updated: 2018/04/16 08:03:22 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int		ft_isnumber(char *number)
{
	int	i;

	i = -1;
	while (number[++i])
	{
		if (!ft_isdigit(number[i]))
			return (FALSE);
	}
	return (TRUE);
}

double	get_length(t_vect *vect)
{
	double	module;

	module = 0;
	module += vect->vect_x * vect->vect_x;
	module += vect->vect_y * vect->vect_y;
	module += vect->vect_z * vect->vect_z;
	return (sqrt(module));
}
