#include "Ray_tracing.h"

int main()
{
  t_mlx mlx;

  mlx.mlx_ptr = mlx_init();
  mlx.mlx_wind = mlx_new_window(mlx.mlx_ptr, 1000, 1000, "this is a circle");
  mlx.img.img_width = 500;
  mlx.img.img_hight = 500;
  mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, mlx.img.img_width, mlx.img.img_hight);
  mlx.img.data = mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_line, &mlx.img.endian);
  /*put_pixel(30, 30, 0xffffff, mlx);*/
  mlx.img.x_start = 100;
  mlx.img.y_start = 100;
  put_circle(mlx, 0xffffff); 
  mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_wind, mlx.img.img_ptr, mlx.img.x_start, mlx.img.y_start);
  mlx_loop(mlx.mlx_ptr);
  

  return (0);
  
} 
