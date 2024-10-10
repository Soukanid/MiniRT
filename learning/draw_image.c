#include "Ray_tracing.h"

void  put_pixel(int x, int y, int color, t_mlx mlx)
{
  int pixel_offset;

  pixel_offset = (y * mlx.img.size_line) + (x * (mlx.img.bpp / 8));
 *(int *)(mlx.img.data + pixel_offset) = color; 
}

 void put_circle(t_mlx mlx, int color)
{
  int diameter;
  int x_center;
  int y_center;
  int current_x;
  int current_y;
  int i;
  int j;

  (void) color;
  i = 0;
  x_center = mlx.img.x_start + mlx.img.img_width / 2;
  y_center = mlx.img.y_start + mlx.img.img_hight / 2;
  diameter = mlx.img.img_hight / 4;
  current_x = mlx.img.x_start;
  current_y = mlx.img.y_start;
  while (i < mlx.img.img_hight)
  {
    j = 0;
    while (j < mlx.img.img_width)
    {
      if (distance_two_point(j + current_x, i + current_y, x_center, y_center) < diameter)
          put_pixel(j, i, color, mlx);
      else
          put_pixel(j, i, 0xf4f400, mlx);
      j++;
    }
    i++;
  }
    
}
