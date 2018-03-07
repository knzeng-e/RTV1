#include "rt_v1.h"


t_matrix		matrix_multiply(t_matrix *mat1, t_matrix *mat2)
{
	t_matrix	result;




	int		i;
	int		j;
	int		k;
	double	val;
	double r[4][4];


	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
		{
			val = 0;
			for (k = 0; k < 4; k++)
				val += mat1[i][k] * mat2[k][j];
			r[i][j] = val;
		}
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			res[i][j] = r[i][j];

}
