/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_origin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 09:57:49 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/11/25 04:07:44 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt_v1.h"

void	set_origin(int i, int j, t_ray *ray, t_params *params)
{

	ray->origin.vect_x = i;
	ray->origin.vect_y = j;
	ray->origin.vect_z = 0;
	ray->direction.vect_x = 0;
	ray->direction.vect_y = 0;
	ray->direction.vect_z = 1;
	ray->t = 20000;
	params->tab_rays[j][i] = ray;
	/*viewPlaneUpLeft + rightVec*xIndent*x - upVec*yIndent*y*/
}
