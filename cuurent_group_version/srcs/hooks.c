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
	/*printf("\nKey pressed ==> %d", keycode);
		fflush(stdout);*/
	if (keycode == ECHAP_KEY)
	{
		quit(params);
		exit (OK);
	}
	if (keycode == R_KEY)
		rotate_z_axis(&(params->eye.orientation), 15, &params->transforms, 0);
	if (keycode == L_KEY)
        params->nb_lights = (params->nb_lights == 2) ? 0 : 2;
	if (keycode == SPACE_KEY)
		params->eye.from.vect_z -= MOVE_DIST;
	if (keycode == LEFT_KEY)
		rotate_y_axis(&(params->eye.to), -15, &params->transforms, 1);
	if (keycode == RIGHT_KEY)
		rotate_y_axis(&(params->eye.to), 15, &params->transforms, 1);
	if (keycode == ZOOM_IN)
		params->fov -= 0.5;
	if (keycode == ZOOM_OUT && params->fov <= MAX_FOV)
		params->fov += 0.5;
	if (keycode == UP_KEY)
		rotate_x_axis(&(params->eye.to), -15, &params->transforms, 1);
	if (keycode == DOWN_KEY)
		rotate_x_axis(&(params->eye.to), 15, &params->transforms, 1);
	expose_hook(params);
	return (keycode);
}
