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
	infos->win = mlx_new_window(infos->mlx, WIDTH, HEIGHT, "RT_V1");
	mlx_put_image_to_window(infos->mlx, infos->win, infos->ptr_img, 0, 0);
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
	init_scene(params);
	printf("\nplane_position : x = %f, y = %f, z = %f", params->plane->position.vect_x, params->plane->position.vect_y, params->plane->position.vect_z);
	printf("\nSphere1_position: x = %f, y = %f, z = %f", params->sphere.center.vect_x, params->sphere.center.vect_y, params->sphere.center.vect_z);
	printf("\n");
	printf("\n");
	track_ray(params);
	mlx_draw(params);
	quit(params);
	return (OK);
}
