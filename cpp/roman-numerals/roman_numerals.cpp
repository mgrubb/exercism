#include <sstream>
#include <iostream>
#include <map>
#include <cassert>
#include <cmath>
#include "roman_numerals.h"

using namespace std;

namespace roman
{
  // d : digit to render, string c is an array of 3 characters that are relavent for the current power of 10
  void render_digit(int d, string c, ostream& os)
  {
    
    if (d == 4)
      os << c[0] << c[1];
    else if (d == 5)
      os << c[1];
    else if (d == 9)
      os << c[0] << c[2];
    else if (d > 5 && d < 9)
      os << c[1] << string(d - 5, c[0]);
    else
      os << string(d, c[0]);
  }
  
  string convert(int n)
  {
    stringstream os;
    int m = n / 1000;
    int c = (n % 1000) / 100;
    int x = (n % 100) / 10;
    int i = (n % 10) / 1;

    os << string(m, 'M');
    render_digit(c, "CDM", os);
    render_digit(x, "XLC", os);
    render_digit(i, "IVX", os);

    return os.str();
  }

}
