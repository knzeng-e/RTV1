/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_v1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 19:51:41 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/11/25 03:53:21 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void	mlx_draw(t_params *infos)
{
	int	KeyPressMask;
	int	KeyPress;

	KeyPressMask = 1L<<0;
	KeyPress = 2;
	//infos->win = mlx_new_window(infos->mlx, WIDTH, HEIGHT, "RTV1");
	//mlx_put_image_to_window(infos->mlx, infos->win, infos->ptr_img, 0, 0);
	//mlx_key_hook(infos->win, key_hook, infos);
	mlx_mouse_hook(infos->win, mouse_hook, infos);
	mlx_expose_hook(infos->win, expose_hook, infos);
	mlx_hook(infos->win, KeyPress, KeyPressMask, key_hook, infos);
	//mlx_hook(infos->win, MOTION_NOTIFY, PTR_MOTION_MASK, pointer_motion, infos);
	mlx_loop(infos->mlx);
}

t_params	*init_params(void)
{
	t_params	*params;

	params = (t_params *)malloc(sizeof(t_params));
	if (params == NULL)
		exit(MALLOC_PARAMS_ERROR);
	params->x_resolution = WIDTH;
	params->y_resolution = HEIGHT;
	return (params);
}

void		quit(t_params *params)
{
	ft_free(params);
}

int		main(void)
{
	t_params	*params;

	params = init_params();
	printf("\nX_resolution => %f\nY_resolution => %f\n", params->x_resolution, params->y_resolution);
	init_scene(params);
	track_ray(params);
	mlx_draw(params);
	quit(params);
	return (OK);
}
