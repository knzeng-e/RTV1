#include "rt_v1.h"

t_matrix		matrix_multiply(t_matrix *mat1, t_matrix *mat2)
{
	t_matrix	result;
	int			i;
	int			j;
	int			k;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
				result.mat[i][j] += mat1->mat[i][k] * mat2->mat[k][j];
		}
	}
	return (result);
}

/*
   for (I=0; I<N; I++)
   for (J=0; J<P; J++)
   {
   C[I][J]=0;
   for (K=0; K<M; K++)
   C[I][J] += A[I][K]*B[K][J];
   }*/

t_vect4			vect_matrx_multiply(t_vect4 *vect, t_matrix *transform)
{
	t_vect4	result;

	result.vect_x = vect->vect_x * transform->mat[0][0] + vect->vect_y * transform->mat[1][0] + vect->vect_z * transform->mat[2][0] + transform->mat[3][0]; 
	result.vect_y = vect->vect_x * transform->mat[0][1] + vect->vect_y * transform->mat[1][1] + vect->vect_z * transform->mat[2][1] + transform->mat[3][1]; 
	result.vect_z = vect->vect_x * transform->mat[0][2] + vect->vect_y * transform->mat[1][2] + vect->vect_z * transform->mat[2][2] + transform->mat[3][2];
	result.vect_w = vect->vect_x * transform->mat[0][3] + vect->vect_z * transform->mat[1][3] + vect->vect_z * transform->mat[2][3] + transform->mat[3][3];
	return (result);
}
