#include "rt_v1.h"

void	set_camera(t_camera *eye)
{
	eye->cam_pos.vect_x = 0;
	eye->cam_pos.vect_y = 0;
	eye->cam_pos.vect_z = -1;
	eye->view_width = 0.5;
	eye->view_height = 0.35;
	eye->view_dist = 1.0;
	eye->vect_dir.vect_x = 0;
	eye->vect_dir.vect_y = 0;
	eye->vect_dir.vect_z = 1;
	eye->up_vect.vect_x = 0;
	eye->up_vect.vect_y = 1;
	eye->up_vect.vect_z = 0;
	eye->right_vect.vect_x = 1;
	eye->right_vect.vect_y = 0;
	eye->right_vect.vect_z = 0;
	eye->is_selected = 0;
}

void	set_vector(t_vect *vect, double x, double y, double z)
{
	vect->vect_x = x;
	vect->vect_y = y;
	vect->vect_z = z;
}

void	set_color(t_color *color, double red, double green, double blue)
{
	color->red = red;
	color->green = green;
	color->blue = blue;
}

int		get_color(t_color color)
{
	return (((color.red & 0xFF) << 16) + ((color.green & 0xFF) << 8) + (color.blue & 0xFF)); 
}

double	get_length(t_vect *vect)
{
	double	module;

	module = 0;
	module += vect->vect_x * vect->vect_x;
	module += vect->vect_y * vect->vect_y;
	module += vect->vect_z * vect->vect_z;
	return (sqrt(module));
}
