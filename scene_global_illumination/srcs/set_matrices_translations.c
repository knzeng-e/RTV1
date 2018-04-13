#include "rt_v1.h"

void	set_translation(t_transform *transforms, double dx, double dy, double dz)
{
	transforms->translation.mat[0][0] = 1;
	transforms->translation.mat[0][1] = 0;
	transforms->translation.mat[0][2] = 0;
	transforms->translation.mat[0][3] = dx;
	transforms->translation.mat[1][0] = 0;
	transforms->translation.mat[1][1] = 1;
	transforms->translation.mat[1][2] = 0;
	transforms->translation.mat[1][3] = dy;
	transforms->translation.mat[2][0] = 0;
	transforms->translation.mat[2][1] = 0;
	transforms->translation.mat[2][2] = 1;
	transforms->translation.mat[2][3] = dz;
	transforms->translation.mat[3][0] = 0;
	transforms->translation.mat[3][1] = 0;
	transforms->translation.mat[3][2] = 0;
	transforms->translation.mat[3][3] = 1;
}
