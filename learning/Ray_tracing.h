#ifndef RAY_TRACING_H
#define RAY_TRACING_H

# define EPSILON 0.00001

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>
#include "mlx.h"

typedef struct s_mlx
{
  void *mlx_ptr;
  void *mlx_wind;
  void *img_ptr;
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

#endif
