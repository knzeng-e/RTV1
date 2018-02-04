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
void	settings(t_ray *ray, double fov, int x, int y)
{
	float	imageAspectRatio;
	float	Px;
	float	Py;

	imageAspectRatio = WIDTH / HEIGHT; // assuming width > height 
	Px = (2 * ((x + 0.5) / WIDTH) - 1) * tan(fov / 2 * M_PI / 180) * imageAspectRatio; 
	Py = (1 - 2 * ((y + 0.5) / HEIGHT)) * tan(fov / 2 * M_PI / 180);
	set_vector(&ray->origin, 0, 0, 0);
	set_vector(&ray->direction, Px, Py, -1);
	ray->direction = substraction(ray->direction, ray->origin); // note that this just equal to Vec3f(Px, Py, -1);
	ray_normalize(&ray->direction); // it's a direction so don't forget to normalize 
}

void	set_origin(int i, int j, t_ray *ray, t_params *params)
{
	//t_vect	view_pixel;

	/*params->eye.right_vect = multiply_vect(params->eye.right_vect, params->x_indent * i);
	params->eye.up_vect = multiply_vect(params->eye.up_vect, params->y_indent * j);
	view_pixel = addition(params->eye.view_left_up, substraction(params->eye.right_vect, params->eye.up_vect));
	params->eye.vect_dir = substraction(view_pixel, params->eye.cam_pos);
	ray_normalize(&params->eye.vect_dir);
	ray->origin.vect_x = i;
	ray->origin.vect_y = j;
	ray->origin.vect_z = 0;
	ray->direction.vect_x = 0;
	ray->direction.vect_y = 0;
	ray->direction.vect_z = 1;*/
	settings(ray, 30, i, j);
	ray->t = 20000;
	ray->ray_normalize = ray_normalize;
	params->tab_rays[j][i] = ray;
	/*viewPlaneUpLeft + rightVec*xIndent*x - upVec*yIndent*y*/
}
