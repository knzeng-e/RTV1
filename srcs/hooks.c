/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 14:00:00 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/12/20 20:41:09 by knzeng-e         ###   ########.fr       */
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

	if (keycode == 53)
		exit (0);
	if (keycode == B_KEY)
		params->sphere2.is_selected = !(params->sphere2.is_selected);
	if (keycode == J_KEY)
		params->sphere.is_selected = !(params->sphere.is_selected);
	if (keycode == V_KEY)
		params->sphere3.is_selected = !(params->sphere3.is_selected);
	if (keycode == C_KEY)
		params->eye.is_selected = !(params->eye.is_selected);
	if (keycode == LEFT_KEY)
	{
		if (params->sphere.is_selected)
		{
			params->sphere.center.vect_x -= 0.2;
		params->light[0].position.vect_x -= 0.2;
		}
		if (params->sphere2.is_selected)
			params->sphere2.center.vect_x -= 0.2;
		if (params->sphere3.is_selected)
			params->sphere3.center.vect_x -= 0.2;
		if (params->eye.is_selected)
			params->plane->normale.vect_x -= 0.5;
	}
	if (keycode == RIGHT_KEY)
	{
		if (params->sphere.is_selected)
		{
			params->light[0].position.vect_x += 0.2;
			params->sphere.center.vect_x += 0.2;
		}
		if (params->sphere2.is_selected)
			params->sphere2.center.vect_x += 0.2;
		if (params->sphere3.is_selected)
			params->sphere3.center.vect_x += 0.2;
		if (params->eye.is_selected)
			params->plane->normale.vect_x += 0.3;
	}
	if (keycode == UP_KEY)
	{
		if (params->sphere.is_selected)
		{
			params->sphere.center.vect_y += 0.2;
		params->light[0].position.vect_z += 0.2;
		}
		if (params->sphere2.is_selected)
			params->sphere2.center.vect_y += 0.2;
			//params->sphere2.center.vect_y += 0.2;
		if (params->sphere3.is_selected)
			params->sphere3.center.vect_z += 0.2;
	}
	if (keycode == DOWN_KEY)
	{
		if (params->sphere.is_selected)
		{
			params->sphere.center.vect_y -= 0.2;
		params->light[0].position.vect_z -= 0.2;
		}
		if (params->sphere2.is_selected)
			params->sphere2.center.vect_y -= 0.2;
		if (params->sphere3.is_selected)
			params->sphere3.center.vect_z -= 0.2;
	}
	expose_hook(params);
	return (keycode);
}
