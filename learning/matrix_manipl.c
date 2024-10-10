#include "Ray_tracing.h"

  
  //for now we don't have a clear idea how we are gonna fill that int**
  //but we are gonna see what we can do

bool  compare_matrix(int **mat1, int **mat2, int hight, int width)
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
        return (false);
    }
  }
  return (true);
}

