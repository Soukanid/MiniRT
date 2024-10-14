#ifndef RAY_TRACING_H
#define RAY_TRACING_H

# define EPSILON 0.00001

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>
#include "mlx.h"


typedef struct s_img
{
  void *img_ptr;
  int bpp;
  int size_line;
  char  *data;
  int endian;
  int x_start;
  int y_start;
  int img_width;
  int img_hight;
} t_img;

typedef struct s_mlx
{
  void *mlx_ptr;
  void *mlx_wind;
  t_img img;
} t_mlx;

typedef struct tuple
{
  float x;
  float y;
  float z;
  float w; // if 1 the tuple is a point and if 0 the tuple is a vector
} tuple;

typedef struct color
{
  float red;
  float green;
  float blue;
} rgb;


void  put_pixel(int x, int y, int color, t_mlx mlx);
  
int distance_two_point(int x1, int y1, int x2, int y2);
bool  compare_matrix(int mat1[][4], int mat2[][4], int hight, int width);
tuple new_tuple(float x, float y, float z, float w);
void put_circle(t_mlx mlx, int color);
void test_matrix();
void test_determinant();
#endif
