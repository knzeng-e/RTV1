/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_v1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 19:51:41 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/02/18 11:48:52 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void		mlx_draw(t_params *infos)
{
	int	key_press_mask;
	int	key_press;

	key_press_mask = 1L << 0;
	key_press = 2;
	init_scene(infos);
	mlx_mouse_hook(infos->win, mouse_hook, infos);
	mlx_expose_hook(infos->win, expose_hook, infos);
	mlx_hook(infos->win, key_press, key_press_mask, key_hook, infos);
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

int			main(void)
{
	t_params	*params;

	params = init_params();
	init_mlx(params);
	mlx_draw(params);
	quit(params);
	return (OK);
}