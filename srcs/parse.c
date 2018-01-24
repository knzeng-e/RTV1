/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:29:26 by knzeng-e          #+#    #+#             */
/*   Updated: 2018/01/23 19:55:59 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt_v1.h"
# include <sys/types.h>
# include <fcntl.h>

int		check_sphere(char *line)
{
	return (ft_strcmp(line, "sphere") == 0);
}

int		check_plane(char *line)
{
	return (ft_strcmp(line, "plane") == 0);
}

int		check_cone(char *line)
{
	return (ft_strcmp(line, "cone") == 0);
}

int		check_cylinder(char *line)
{
	return (ft_strcmp(line, "cylinder") == 0);
}

int		check_object(char *line)
{
	return (check_sphere(line) || (check_plane(line)) || (check_cone(line)) \
	|| (check_cylinder(line)));
}

void	ft_parse_error(int num_line)
{
	ft_putstr(PARSE_ERROR_MESSAGE);
	ft_putnbr(num_line);
	exit (-2);
}

void	read_line(char *file)
{
	char	*line;
	int		cpt;
	int		num_line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit (-1);
	cpt = 1;
	num_line = 1;
	while (get_next_line(fd, &line))
	{
		if (check_object(line) == 0 && (ft_strlen(line) != 0))
		{
			ft_putstr(PARSE_ERROR_MESSAGE);
			ft_putnbr(num_line);
			exit (-2);
		}
		while (ft_strcmp(line, "}"))
		{
			if (ft_strlen(line) == 0)
			{
				get_next_line(fd, &line);
				if (ft_strlen(line) == 0)
					ft_parse_error(num_line);
			}
			if (line[0] == '}')
				ft_parse_error(num_line);
			get_next_line(fd, &line);
			num_line++;
			ft_putstr(line);
			ft_putchar('\n');
		}
		cpt++;
		num_line++;
	}
}

