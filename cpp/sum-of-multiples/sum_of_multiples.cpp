#include "sum_of_multiples.h"

using namespace std;

namespace som = sum_of_multiples;

int som::to(set<int> f, int n)
{
  int sum = 0;
  bool factor = false;
  for (int i = 1; i < n; ++i)
  {
    for (int j : f)
      if (i % j == 0)
      {
        sum += i;
        break;
      }
  }

  return sum;
}
