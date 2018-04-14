/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 20:43:06 by neprocur          #+#    #+#             */
/*   Updated: 2018/04/04 20:43:33 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int				ft_isnumber(char *number)
{
	int			i;

	i = -1;
	while (number[++i])
	{
		if (!ft_isdigit(number[i]))
			return (FALSE);
	}
	return (TRUE);
}
