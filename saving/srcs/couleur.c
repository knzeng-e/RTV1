/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   couleur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 07:39:00 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/02/06 12:18:16 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int	couleur(double angle)
{
	return ((RGB(127.5 * (cos(angle) + 1), 127.5 * (sin(angle) + 1), 127.5 * (1 - cos(angle)))));
}
