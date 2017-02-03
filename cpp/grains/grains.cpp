#include <cmath>
#include "grains.h"

namespace grains
{
  unsigned long long square(int n)
  {
    return pow(2,n-1);
  }

  unsigned long long total()
  {
    unsigned long long sum = 0;
    for(int i = 1; i < 65; ++i)
      sum += square(i);
    return sum;
  }
  
}
