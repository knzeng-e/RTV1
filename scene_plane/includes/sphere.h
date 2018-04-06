/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 02:00:59 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/02/18 11:58:38 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H

# define SPHERE_H

typedef struct	s_sphere
{
	int						color;
	int						is_selected;
	double				rayon;
	double				specular;
	t_vect				center;
}								t_sphere;
#endif
