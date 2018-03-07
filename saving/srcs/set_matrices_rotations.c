#include "rt_v1.h"

void	set_x_rotation(t_transform *transforms, double angle)
{
	transforms->x_rotation[0][0] = 1;
	transforms->x_rotation[0][1] = 0;
	transforms->x_rotation[0][2] = 0;
	transforms->x_rotation[0][3] = 0;
	transforms->x_rotation[1][0] = 0;
	transforms->x_rotation[1][1] = cos(angle);
	transforms->x_rotation[1][2] = -sin(angle);
	transforms->x_rotation[1][3] = 0;
	transforms->x_rotation[2][0] = 0;
	transforms->x_rotation[2][1] = sin(angle);
	transforms->x_rotation[2][2] = cos(angle);
	transforms->x_rotation[2][3] = 0;
	transforms->x_rotation[3][0] = 0;
	transforms->x_rotation[3][1] = 0;
	transforms->x_rotation[3][2] = 0;
	transforms->x_rotation[3][3] = 1;
}

void	set_y_rotation(t_transform *transforms, double angle)
{
	transforms->y_rotation[0][0] = cos(angle);
	transforms->y_rotation[0][1] = 0;
	transforms->y_rotation[0][2] = sin(angle);
	transforms->y_rotation[0][3] = 0;
	transforms->y_rotation[1][0] = 0;
	transforms->y_rotation[1][1] = 1;
	transforms->y_rotation[1][2] = 0;
	transforms->y_rotation[1][3] = 0;
	transforms->y_rotation[2][0] = -sin(angle);
	transforms->y_rotation[2][1] = 0;
	transforms->y_rotation[2][2] = cos(angle);
	transforms->y_rotation[2][3] = 0;
	transforms->y_rotation[3][0] = 0;
	transforms->y_rotation[3][1] = 0;
	transforms->y_rotation[3][2] = 0;
	transforms->y_rotation[3][3] = 1;
}

void	set_z_rotation(t_transform *transforms, double angle)
{
	transforms->z_rotation[0][0] = cos(angle);
	transforms->z_rotation[0][1] = -sin(angle);
	transforms->z_rotation[0][2] = 0;
	transforms->z_rotation[0][3] = 0;
	transforms->z_rotation[1][0] = sin(angle);
	transforms->z_rotation[1][1] = cos(angle);
	transforms->z_rotation[1][2] = 0;
	transforms->z_rotation[1][3] = 0;
	transforms->z_rotation[2][0] = 0;
	transforms->z_rotation[2][1] = 0;
	transforms->z_rotation[2][2] = 1;
	transforms->z_rotation[2][3] = 0;
	transforms->z_rotation[3][0] = 0;
	transforms->z_rotation[3][1] = 0;
	transforms->z_rotation[3][2] = 0;
	transforms->z_rotation[3][3] = 1;
}
