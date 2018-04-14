/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 14:00:00 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/04/15 00:42:06 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int		expose_hook(t_params *infos)
{
	ft_bzero(infos->img_data, HEIGHT * infos->size_line);
	mlx_clear_window(infos->mlx, infos->win);
	track_ray(infos);
	mlx_put_image_to_window(infos->mlx, infos->win, infos->ptr_img, 0, 0);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_params *infos)
{
	ft_putstr("\nNew_clic of button ");
	ft_putnbr(button);
	ft_putstr(" on (");
	ft_putnbr(x);
	ft_putstr(", ");
	ft_putnbr(y);
	ft_putstr(")");

	expose_hook(infos);
	return (0);
}

int		key_hook(int keycode, t_params *params)
{

//	printf("\nKey pressed ==> %d", keycode);
//		fflush(stdout);
	if (keycode == I_KEY)
		params->light[0].intensity += 0.5;
	if (keycode == 53)
	{
		quit(params);
		exit (OK);
	}
	if (keycode == V_KEY)
		params->sphere_list[1].is_selected = !(params->sphere_list[1].is_selected);
	if (keycode == J_KEY)
		params->sphere_list[0].is_selected = !(params->sphere_list[0].is_selected);
	if (keycode == B_KEY)
		params->sphere_list[2].is_selected = !(params->sphere_list[2].is_selected);
	if (keycode == R_KEY)
		params->sphere_list[3].is_selected = !(params->sphere_list[3].is_selected);
	if (keycode == L_KEY)
    {
        params->nb_lights = (params->nb_lights == 2) ? 0 : 2;
    }
	if (keycode == SPACE_KEY)
	{
		//params->eye.to.vect_y -= 0.04;
		//	params->eye.from.vect_x = 0.01;
		params->eye.from.vect_z += 0.01;
		params->eye.from.vect_x -= 0.01;
		//params->eye.from.vect_y += 0.01;
		//	printf("\neye_from: [%f, %f, %f]", params->eye.from.vect_x, params->eye.from.vect_y, params->eye.from.vect_z);
		//	printf("\neye_to: [%f, %f, %f]", params->eye.to.vect_x, params->eye.to.vect_y, params->eye.to.vect_z);
		//params->rotation_val += 5;
		//	rotate_y_axis(&(params->eye.to), 10, &params->transforms);
		//rotate_x_axis(&(params->cylinder_list[0].center), 30, &params->transforms);
		//rotate_x_axis(&(params->cylinder_list[0].axe), 1.3, &params->transforms);
		//	rotate_y_axis(&(params->cylinder_list[0].axe), 2, &params->transforms);
		//rotate_z_axis(&(params->cone_list[0].axe), 2, &params->transforms);
	}
	if (keycode == LEFT_KEY)
	{
		//rotate_y_axis(&(params->eye.to), 1, &params->transforms, 1);
		params->eye.to.vect_x = 0.04;
		/*if (params->sphere_list[0].is_selected)
		  params->sphere_list[0].center.vect_x -= MOVE_DIST;
		  if (params->sphere_list[1].is_selected)
		  params->sphere_list[1].center.vect_x -= MOVE_DIST;
		  if (params->sphere_list[2].is_selected)
		  params->sphere_list[2].center.vect_x -= MOVE_DIST;
		  if (params->sphere_list[3].is_selected)
		  params->sphere_list[3].center.vect_x -= MOVE_DIST;
		  if (params->light[0].is_selected)
		  params->light[0].position.vect_x -= MOVE_DIST;*/
	}
	if (keycode == RIGHT_KEY)
	{
		/*rotate_z_axis(&(params->eye.to), 10, &params->transforms);
		  rotate_x_axis(&(params->eye.to), 10, &params->transforms);
		  rotate_y_axis(&(params->eye.to), 10, &params->transforms);*/

		//rotate_z_axis(&(params->eye.from), 2.3, &params->transforms, 1);
		//rotate_x_axis(&(params->eye.from), 2.3, &params->transforms, 1);
		//rotate_y_axis(&(params->eye.from), 2.3, &params->transforms, 1);
		params->eye.to.vect_x -= 0.04;
		/*	if (params->sphere_list[0].is_selected)
			params->sphere_list[0].center.vect_x += MOVE_DIST;
			if (params->sphere_list[1].is_selected)
			params->sphere_list[1].center.vect_x += MOVE_DIST;
			if (params->sphere_list[2].is_selected)
			params->sphere_list[2].center.vect_x += MOVE_DIST;
			if (params->sphere_list[3].is_selected)
			params->sphere_list[3].center.vect_x += MOVE_DIST;
			if (params->light[0].is_selected)
			params->light[0].position.vect_x += MOVE_DIST;*/
	}
	if (keycode == ZOOM_IN)
		params->fov -= 0.5;
	if (keycode == ZOOM_OUT && params->fov <= MAX_FOV)
		params->fov += 0.5;
	if (keycode == UP_KEY)
	{
		params->rotation_val += 5;
		//params->eye.to.vect_y -= 0.04;
		/*if (params->sphere_list[0].is_selected)
		  params->sphere_list[0].center.vect_y += MOVE_DIST;
		  if (params->sphere_list[1].is_selected)
		  params->sphere_list[1].center.vect_y += MOVE_DIST;
		  if (params->sphere_list[2].is_selected)
		  params->sphere_list[2].center.vect_y += MOVE_DIST;
		  if (params->sphere_list[3].is_selected)
		  params->sphere_list[3].center.vect_y += MOVE_DIST;
		  if (params->light[0].is_selected)
		  params->light[0].position.vect_y += MOVE_DIST;*/
	}
	if (keycode == DOWN_KEY)
	{
		params->rotation_val -= 5;
		//params->eye.to.vect_y += 0.04;
		/*if (params->sphere_list[0].is_selected)
		  params->sphere_list[0].center.vect_y -= MOVE_DIST;
		  if (params->sphere_list[1].is_selected)
		  params->sphere_list[1].center.vect_y -= MOVE_DIST;
		  if (params->sphere_list[2].is_selected)
		  params->sphere_list[2].center.vect_y -= MOVE_DIST;
		  if (params->sphere_list[3].is_selected)
		  params->sphere_list[3].center.vect_y -= MOVE_DIST;
		  if (params->light[0].is_selected)
		  params->light[0].position.vect_y -= MOVE_DIST;*/
	}
	expose_hook(params);
	return (keycode);
}
