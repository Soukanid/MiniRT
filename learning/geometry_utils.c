#include "Ray_tracing.h"

int distance_two_point(int x1, int y1, int x2, int y2)
{
  return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}
