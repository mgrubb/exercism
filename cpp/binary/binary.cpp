#include <algorithm>
#include <cmath>
#include "binary.h"

using namespace std;

namespace binary
{
  int convert(string n)
  {
    int sum = 0;
    if (!all_of(n.begin(), n.end(), ::isdigit))
      return 0;

    reverse(n.begin(), n.end());
    for(int i = 0; i < n.size(); ++i)
      if (n[i] == '1')
        sum += pow(2,i);
    return sum;
  }
}
