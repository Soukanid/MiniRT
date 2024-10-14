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

void  matrix_multiple_matrix(int mat1[][4], int mat2[][4], int width, int hight, int mat_res[][4])
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

void  transpose_matrix(int mat[][4],int width, int hight, int mat_res[][4])
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

void  print_matrix(int matrix[][4], int width, int hight)
{
  int i;
  int j;

  i = 0;
  while (i < hight)
  {
    j = 0;
    while (j < width)
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
  print_matrix(matrix, 4, 4);
  transpose_matrix(matrix, 4, 4, resm);
  print_matrix(resm, 4, 4);
  compare_matrix(matrix, matrix, 4, 4);  
}

int determinant(int matrix[][4])
{
  int det;

  det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
  return (det);
}

void  submatrix(int matrix[][4], int res[][4], int width, int hight,int line, int colmn)
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


int minor(int matrix[][4], int line, int colmn, int width, int hight)
{
  int res_matrix[4][4];

  submatrix(matrix, res_matrix, width - 1, hight - 1, line, colmn);
  return (determinant(res_matrix));
}


int cofactor(int mat[][4], int width, int hight, int line, int colmn)
{
  if ((line + colmn) % 2 == 0)
    return (minor(mat, line, colmn, width, hight));
  return (-1 * minor(mat, line, colmn, width, hight));
}

int determinant_tree(int mat[][4], int width, int hight)
{
  int j;
  int det;

  det = 1;
  j = 0;
  while (j < 3)
  {
    det = det + mat[0][j] * cofactor(mat, width, hight, 0, j);
    j++;
    printf("i have been here %d\n\n", mat[0][j]);
  }
  return (det);
}

int determinant_matrix(int mat[][4], int width, int hight)
{
  int i;
  int det;
  int tmp_det;
  int sub_matrix[4][4];
  int sign;
  
  i = 0;
  det = 0;
  while (i < 4)
  {
    tmp_det = 0;
    submatrix(mat, sub_matrix, width, hight, 0, i);
    tmp_det = determinant_tree(sub_matrix, 4, 4);
    printf("%d\n\n\n", tmp_det);
    if (i % 2 == 0)
      sign = 1;
    else 
      sign = -1;
    det = mat[0][i] * sign * tmp_det + det;
    i++;
  }
  return (det);
}


void test_determinant()
{
  int mat[4][4] = { {-2 , -8 , 3 , 5 }
                 , {-3 , 1 , 7 ,  3 }
                  , {1 , 2 , -9 , 6 }
                  , {-6 , 7 , 7 ,-9} };
  
  printf("the det is %d\n\n\n",determinant_matrix(mat, 4, 4));
}

void  inversion_of_matrix(int mat[][4], int res_mat[][4])
{
  int det;
  int i;
  int j;

  i = 0;
  det = determinant_matrix(mat, 4, 4);
  while (i < 4)
  {
    while (j < 4)
  }
}




