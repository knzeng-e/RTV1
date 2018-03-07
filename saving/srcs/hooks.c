/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 14:00:00 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/03/07 23:56:28 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int		ft_free_rays(t_params *params)
{
	int	i;
	int	j;
	int	cpt;

	i = -1;
	cpt = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
		{
			if (++cpt <= params->rays_to_free)
			{
				free(params->tab_rays[j][i]);
				params->rays_to_free--;
			}
			else
				return (FREE_OK);
		}
	}
	return (-1);
}

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
	//printf("\nKey pressed ==> %d", keycode);
	if (keycode == I_KEY)
		params->light[0].intensity += 0.5;
	if (keycode == 53)
		exit (0);
	if (keycode == V_KEY)
		params->sphere_list[1].is_selected = !(params->sphere_list[1].is_selected);
	if (keycode == J_KEY)
		params->sphere_list[0].is_selected = !(params->sphere_list[0].is_selected);
	if (keycode == B_KEY)
		params->sphere_list[2].is_selected = !(params->sphere_list[2].is_selected);
	if (keycode == R_KEY)
		params->sphere_list[3].is_selected = !(params->sphere_list[3].is_selected);
	if (keycode == L_KEY)
		params->light[0].is_selected = !(params->light[0].is_selected);
	if (keycode == SPACE_KEY)
	{
		//rotate_x_axis(&(params->cylinder_list[0].center), 30, &params->transforms);
		rotate_y_axis(&(params->sphere_list[0].center), 15, &params->transforms);
	}
	if (keycode == LEFT_KEY)
	{
		if (params->sphere_list[0].is_selected)
			params->sphere_list[0].center.vect_x -= MOVE_DIST;
		if (params->sphere_list[1].is_selected)
			params->sphere_list[1].center.vect_x -= MOVE_DIST;
		if (params->sphere_list[2].is_selected)
			params->sphere_list[2].center.vect_x -= MOVE_DIST;
		if (params->sphere_list[3].is_selected)
			params->sphere_list[3].center.vect_x -= MOVE_DIST;
		if (params->light[0].is_selected)
			params->light[0].position.vect_x -= MOVE_DIST;
	}
	if (keycode == RIGHT_KEY)
	{
		if (params->sphere_list[0].is_selected)
			params->sphere_list[0].center.vect_x += MOVE_DIST;
		if (params->sphere_list[1].is_selected)
			params->sphere_list[1].center.vect_x += MOVE_DIST;
		if (params->sphere_list[2].is_selected)
			params->sphere_list[2].center.vect_x += MOVE_DIST;
		if (params->sphere_list[3].is_selected)
			params->sphere_list[3].center.vect_x += MOVE_DIST;
		if (params->light[0].is_selected)
			params->light[0].position.vect_x += MOVE_DIST;
	}
	if (keycode == ZOOM_IN)
		params->fov -= 0.5;
	if (keycode == ZOOM_OUT && params->fov <= MAX_FOV)
		params->fov += 0.5;
	if (keycode == UP_KEY)
	{
		if (params->sphere_list[0].is_selected)
			params->sphere_list[0].center.vect_y += MOVE_DIST;
		if (params->sphere_list[1].is_selected)
			params->sphere_list[1].center.vect_y += MOVE_DIST;
		if (params->sphere_list[2].is_selected)
			params->sphere_list[2].center.vect_y += MOVE_DIST;
		if (params->sphere_list[3].is_selected)
			params->sphere_list[3].center.vect_y += MOVE_DIST;
		if (params->light[0].is_selected)
			params->light[0].position.vect_y += MOVE_DIST;
	}
	if (keycode == DOWN_KEY)
	{
		if (params->sphere_list[0].is_selected)
			params->sphere_list[0].center.vect_y -= MOVE_DIST;
		if (params->sphere_list[1].is_selected)
			params->sphere_list[1].center.vect_y -= MOVE_DIST;
		if (params->sphere_list[2].is_selected)
			params->sphere_list[2].center.vect_y -= MOVE_DIST;
		if (params->sphere_list[3].is_selected)
			params->sphere_list[3].center.vect_y -= MOVE_DIST;
		if (params->light[0].is_selected)
			params->light[0].position.vect_y -= MOVE_DIST;
	}
	expose_hook(params);
	return (keycode);
}
