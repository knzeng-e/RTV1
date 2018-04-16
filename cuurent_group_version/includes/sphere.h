/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 02:00:59 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/16 07:03:03 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H

# define SPHERE_H

typedef struct	s_sphere
{
	int			color;
	int			is_selected;
	double		rayon;
	double		specular;
	t_vect		center;
}				t_sphere;
#endif
