/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayon.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 00:10:43 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/16 07:00:25 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYON_H

# define RAYON_H
# include "vector.h"

typedef struct	s_ray
{
	t_vect		origin;
	t_vect		direction;
	t_vect		intersection;
	double		t;
	double		t_min;
	double		t_max;
	int			is_inter;
}				t_ray;
#endif
