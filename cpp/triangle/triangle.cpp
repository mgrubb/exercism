#include <iostream>
#include <stdexcept>
#include <cmath>
#include "triangle.h"

using namespace std;

namespace triangle
{
  triangle_type kind(float a, float b, float c)
  {
    if ( a <= 0 || b <= 0 || c <= 0 || !((c < a + b) && (c > abs(a - b))))
      throw domain_error("Impossible Triangle");
    else if (a == b && b == c)
           return equilateral;
         else if ( a == b || a == c || b == c)
           return isosceles;
         else
           return scalene;
  }
}
