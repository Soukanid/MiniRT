#include "Ray_tracing.h"

  
  //for now we don't have a clear idea how we are gonna fill that int**
  //but we are gonna see what we can do

bool  compare_matrix(int mat1[][4], int mat2[][4], int hight, int width)
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

void  matrix_multiple_matrix(int mat1[][4], int mat2[][4], int mat_res[][4])
{
  int i;
  int j;
  
  i = 0;
  while(i < 4)
  {
    j = 0;
    while(j < 4)
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

tuple matrix_multiple_tuple(int mat[][4], tuple t)
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

void  transpose_matrix(int mat[][4], int mat_res[][4])
{
  int i;
  int j;

  i = 0;
  while (i < 4)
  {
    j = 0;
    while (j < 4)
    {
      mat_res[j][i] = mat[i][j];
      j++;
    }
    i++;
  }
}

void  print_matrix(int matrix[][4])
{
  int i;
  int j;

  i = 0;
  while (i < 4)
  {
    j = 0;
    while (j < 4)
    {
      printf("%d ", matrix[i][j]);
      j++;
    }
    printf("\n");
    i++;
  }
}

void test_matrix()
{
  int matrix[4][4];
  /*tuple test;*/

  /*test = new_tuple(1, 1, 1, 1);*/
  int i = 0, j = 0;
  while (i < 4)
  {
    j = 0;
    while(j < 4)
    {
      matrix[i][j] = j;
      j++;
    }
    i++;
  }
  int resm[4][4];
  print_matrix(matrix);
  transpose_matrix(matrix, resm);
  print_matrix(resm);
  compare_matrix(matrix, matrix, 4, 4);  
}

int determinant(int matrix[][2])
{
  int det;

  det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
  return (det);
}

void  submatrix_tree(int matrix[][4], int res[][3],int line, int colmn)
{
  int i;
  int j;
  int k;
  int l;

  i = 0;
  k = 0;
  while(i < 4)
  {
    j = 0;
    l = 0;
    while (j < 4)
    {
      if (i != line && j != colmn)
      {
        res[k][l] = matrix[i][j];
        l++;
      }
    }
    i++;
    if (line != i)
      k++;
  }
}

void  submatrix_two(int matrix[][3], int res[][2],int line, int colmn)
{
  int i;
  int j;
  int k;
  int l;

  i = 0;
  k = 0;
  while(i < 3)
  {
    j = 0;
    l = 0;
    while (j < 3)
    {
      if (i != line && j != colmn)
      {
        res[k][l] = matrix[i][j];
        l++;
      }
    }
    i++;
    if (line != i)
      k++;
  }
}

int minor(int matrix[][3], int line, int colmn)
{
  int res_matrix[2][2];

  submatrix_two(matrix, res_matrix, line, colmn);
  return (determinant(res_matrix));
}












