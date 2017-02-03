#include <boost/math/special_functions/prime.hpp>
#include "prime_factors.h"

using namespace std;
using namespace boost;

vector<int> prime_factors::of(int n)
{
  vector<int> factors;
  int p = 0;
  int prime;
  while (n != 1)
  {
    prime = math::prime(p++);
    while (n % prime == 0)
    {
      n /= prime;
      factors.push_back(prime);
    }
  }

  return vector<int>(factors);
}
