#include "rt_v1.h"

int	check_sphere_params(char **line_content)
{
	static int	cpt_params = 4; /* position, color, rayon, specular  */

		if (cpt_params <= 0)
			return (ERROR_NB_PARAMS);
		while (*line_content)
		{
			if (ft_strcmp(*line_content, "center:") || ft_strcmp(*line_content, "position:"))
			{
				cpt_params--;
				if (get_sphere_position(line_content) == 0)
					return (0);
			}
			ft_putstr("\n- ");
			ft_putstr(*line_content);
			(line_content)++;
			ft_putchar('\n');
		}
}

int	check_plane_params(char **line_content)
{
	static int	cpt_params = 4; /* position, normal, color, specular */
}

int	check_cylinder_params(char **line_content)
{
	static int	cpt_params = 4; /* radius, specular, cposition, color */
}

int	check_cone_params(char **line_content)
{
	static int	cpt_params = 4; /* position, angle, specular, color */
}

int	check_light_params(char **line_content)
{
	static int	cpt_params = 3; /* position, intensity, type */
}
