/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:13:59 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/09 21:39:30 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H

# define VECTOR_H

typedef struct	s_vect
{
	double		vect_x;
	double		vect_y;
	double		vect_z;
}				t_vect;

typedef struct	s_point
{
	double		point_x;
	double		point_y;
	double		point_z;
}				t_point;

#endif
