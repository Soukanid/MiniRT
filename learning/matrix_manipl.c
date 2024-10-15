#include "Ray_tracing.h"
  
  //for now we don't have a clear idea how we are gonna fill that int**
  //but we are gonna see what we can do

bool  compare_matrix(float mat1[][4], float mat2[][4], int hight, int width)
{
  int i;
  int j;

  i = 0;
  while (i < hight)
  {
    j = 0;
    while (j < width)
    {
      if (mat1[i][j] != mat2[i][j])
      {
        printf("false\n\n\n");
        return (false);
      }
      j++;
    }
    i++;
  }
  printf("true\n\n\n");
  return (true);
}

void  matrix_multiple_matrix(float mat1[][4], float mat2[][4], int width, int hight, float mat_res[][4])
{
  int i;
  int j;
  
  i = 0;
  while(i < hight)
  {
    j = 0;
    while(j < width)
    {
      mat_res[i][j] = mat1[i][0] * mat2[0][j]
                      + mat1[i][1] * mat2[1][j]
                      + mat1[i][2] * mat2[2][j]
                      + mat1[i][3] * mat2[3][j];
      j++;
    }
    i++;
  }
}

tuple matrix_multiple_tuple(float mat[][4], tuple t)
{
  int i;
  int res[4];

  i = 0;
  while(i < 4)
  {
    res[i] = mat[i][0] * t.x +
                  mat[i][1] * t.y +
                  mat[i][2] * t.z +
                  mat[i][3] * t.w ; 
    i++;
  }
  return (new_tuple(res[0], res[1], res[2], res[3]));
}

void  transpose_matrix(float mat[][4],int width, int hight, float mat_res[][4])
{
  int i;
  int j;

  i = 0;
  while (i < hight)
  {
    j = 0;
    while (j < width)
    {
      mat_res[j][i] = mat[i][j];
      j++;
    }
    i++;
  }
}

void  print_matrix(float matrix[][4], int width, int hight)
{
  int i;
  int j;

  i = 0;
  while (i < hight)
  {
    j = 0;
    while (j < width)
    {
      printf("%f ", matrix[i][j]);
      j++;
    }
    printf("\n");
    i++;
  }
}
/**/
/*void test_matrix()*/
/*{*/
/*  int matrix[4][4];*/
/*  tuple test;*/
/**/
/*  test = new_tuple(1, 1, 1, 1);*/
/*  int i = 0, j = 0;*/
/*  while (i < 4)*/
/*  {*/
/*    j = 0;*/
/*    while(j < 4)*/
/*    {*/
/*      matrix[i][j] = j;*/
/*      j++;*/
/*    }*/
/*    i++;*/
/*  }*/
/*  int resm[4][4];*/
/*  print_matrix(matrix, 4, 4);*/
/*  transpose_matrix(matrix, 4, 4, resm);*/
/*  print_matrix(resm, 4, 4);*/
/*  compare_matrix(matrix, matrix, 4, 4);  */
/*}*/

float determinant(float matrix[][4])
{
  int det;

  det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
  return (det);
}

void  submatrix(float matrix[][4], float res[][4], int width, int hight,int line, int colmn)
{
  int i;
  int j;
  int k;
  int l;

  i = 0;
  k = 0;
  while(i < hight)
  {
    j = 0;
    l = 0;
    while (j < width)
    {
      if (i != line && j != colmn)
      {
        res[k][l] = matrix[i][j];
        l++;
      }
      j++;
    }
    if (line != i)
      k++;
    i++;
  }
}


float minor(float matrix[][4], int line, int colmn, int width, int hight)
{
  float res_matrix[4][4];

  submatrix(matrix, res_matrix, width - 1, hight - 1, line, colmn);
  return (determinant(res_matrix));
}


float cofactor(float mat[][4], int width, int hight, int line, int colmn)
{
  if ((line + colmn) % 2 == 0)
    return (minor(mat, line, colmn, width, hight));
  return (-1 * minor(mat, line, colmn, width, hight));
}

float determinant_tree(float mat[][4], int width, int hight)
{
  int j;
  float det;

  det = 1;
  j = 0;
  while (j < 3)
  {
    det = det + mat[0][j] * cofactor(mat, width, hight, 0, j);
    j++;
  }
  return (det);
}

float determinant_matrix(float mat[][4], int width, int hight)
{
  int i;
  float det;
  float tmp_det;
  float sub_matrix[4][4];
  int sign;
  
  i = 0;
  det = 0;
  while (i < 4)
  {
    tmp_det = 0;
    submatrix(mat, sub_matrix, width, hight, 0, i);
    tmp_det = determinant_tree(sub_matrix, 4, 4);
    if (i % 2 == 0)
      sign = 1;
    else 
      sign = -1;
    det = mat[0][i] * sign * tmp_det + det;
    i++;
  }
  return (det);
}



void  inversion_of_matrix(float mat[][4], float res_mat[][4])
{
  float det;
  float tmp_det;
  int i;
  int j;
  float sub_matrix[4][4];

  i = 0;
  det = determinant_matrix(mat, 4, 4);
  while (i < 4)
  {
    j = 0;
    while (j < 4)
    {
      submatrix(mat, sub_matrix, 4, 4, j, i);
      tmp_det = determinant_tree(sub_matrix, 4, 4);
      if ((j + i) % 2 != 0)
        tmp_det *= -1;
      res_mat[i][j] = tmp_det / det;
      j++;
    }
    i++;
  }
}

void test_determinant()
{
  float mat[4][4] = { {-5 , 2 , 6 , -8 }
                , {1 , -5 , 1 ,  8 }
                , {7 , 7 , -6 , -7}
                , {1 , -3 , 7 , 4} };
  float res_mat[4][4];
  inversion_of_matrix(mat, res_mat);
  print_matrix(res_mat, 4, 4);
}
