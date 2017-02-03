#include <sstream>
#include "raindrops.h"

using namespace std;

namespace raindrops
{
  string convert(int n)
  {
    stringstream os; bool div = false;
    if (n % 3 == 0)
      {
        os << "Pling";
        div = true;
      }
    if (n % 5 == 0)
      {
        os << "Plang";
        div = true;
      }
    if (n % 7 == 0)
      {
        os << "Plong";
        div = true;
      }
    if (!div)
      os << n;

    return os.str();
  }
}
