/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 02:00:59 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/11/18 04:23:04 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H

# define SPHERE_H

typedef struct	s_color
{
	int			red;
	int			green;
	int			blue;
}				t_color;

typedef struct	s_sphere
{
	double		rayon;
	t_vect		center;
	t_vect		simple_center;
	/*t_vect		location;*/
	t_color		color;
	int			is_selected;
	/*equation of sphere: (x - center.x)^2 + (y - center.y)^2 + (z - center.z)^2 = rayon^2 */
}				t_sphere;
#endif
