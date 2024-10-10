#include "Ray_tracing.h"

int main()
{
  t_mlx mlx;

  mlx.mlx_ptr = mlx_init();
  mlx.mlx_wind = mlx_new_window(mlx.mlx_ptr, 100, 100, "this is a circle");


  return (0);
  
} 
