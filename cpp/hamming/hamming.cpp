#include <string>
#include <stdexcept>
#include "hamming.h"

using namespace std;

int hamming::compute(const char *a, const char *b)
{
  typedef string::iterator si;
  
  string sa(a);
  string sb(b);
  int d = 0;

  if (sa.length() != sb.length())
    throw domain_error ("Strings different length");

  si sai = sa.begin();
  si sbi = sb.begin();

  while (sai != sa.end())
        {
          if (*sai != *sbi) ++d;
          ++sai;
          ++sbi;
        }

  return d;
}
