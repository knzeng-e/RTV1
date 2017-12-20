/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayon.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 00:10:43 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/11/25 04:05:47 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYON_H

# define RAYON_H

typedef struct	s_vect
{
	double		vect_x;
	double		vect_y;
	double		vect_z;
}				t_vect;

typedef struct	s_ray
{
	t_vect		origin;
	t_vect		direction;
	t_vect		intersection;
	double		t;
	void		(*ray_normalize)(t_vect *);
}				t_ray;
#endif
