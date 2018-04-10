/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 02:00:59 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/10 11:58:30 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H

# define SPHERE_H

typedef struct	s_sphere
{
	int			color;
	int			is_selected;
    int         id;
	double		rayon;
	double		specular;
	t_vect		center;
}				t_sphere;
#endif
