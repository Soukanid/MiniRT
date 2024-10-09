#include "Ray_tracing.h"

tuple new_tuple(float x, float y, float z, float w)
{
  tuple new;

  new.x = x;
  new.y = y;
  new.z = z;
  new.w = w;
  return (new);
}

tuple add_tuple(tuple t1, tuple t2)
{
  return (new_tuple(t1.x + t2.x,
                    t1.y + t2.y,
                    t1.z + t2.z,
                    t1.w + t2.w));
}


tuple substr_tuple(tuple t1, tuple t2)
{
  return (new_tuple(t1.x - t2.x,
                    t1.y - t2.y,
                    t1.z - t2.z,
                    t1.w - t2.w));
}


tuple multiply_tuple(tuple t1, tuple t2)
{
  return (new_tuple(t1.x * t2.x,
                    t1.y * t2.y,
                    t1.z * t2.z,
                    t1.w * t2.w));
}


tuple divide_tuple(tuple t1, tuple t2)
{
  return (new_tuple(t1.x / t2.x,
                    t1.y / t2.y,
                    t1.z / t2.z,
                    t1.w / t2.w));
}


tuple negate_tuple(tuple t)
{
  return (new_tuple(-t.x,
                    -t.y,
                    -t.z,
                    -t.w));
}

float magnitude(tuple t)
{
  return (sqrt(pow(t.x, 2) + pow(t.y, 2) + pow(t.z, 2)));
}

tuple normalize_vector(tuple t)
{
  float magn;

  magn = magnitude(t);
  return (new_tuple(t.x / magn, t.y / magn,
          t.z / magn, 0));
}
 float dot(tuple t1 ,tuple t2)
{
  return (t1.x * t2.x + t1.y * t2.y + t1.z * t2.z);
}

tuple cross_product(tuple t1, tuple t2)
{
  return (new_tuple(t1.y * t2.z - t1.z * t2.y,
                    t1.z * t2.x - t1.x * t2.z,
                    t1.x * t2.y - t1.y * t2.x, 0));
}
