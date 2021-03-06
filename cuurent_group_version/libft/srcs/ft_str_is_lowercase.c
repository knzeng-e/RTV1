/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 12:01:53 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/26 12:07:58 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_lowercase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(ft_is_low(str[i])))
			return (0);
		i++;
	}
	return (1);
}
