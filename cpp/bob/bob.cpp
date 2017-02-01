#include <iostream>
#include <string>
#include <algorithm>
#include "bob.h"

using namespace std;

namespace bob
{
  bool is_all_upcase(const string &str)
  {
    string u (str);

    transform(u.begin(), u.end(), u.begin(), ::toupper);
    return str == u;
  }

  bool is_num_char(const char c)
  {
    return ::isdigit(c) || ::isspace(c) || c == ',';
  }
  
  bool is_all_numbers(const string &str)
  {
    int endOffset = 0;
    switch (str.back())
    {
      case '?':
      case '!':
      case '.': endOffset = -1; break;
    }
    return all_of(str.begin(), str.end() + endOffset, is_num_char);
  }
  
  string &trim(string &str)
  {
    string &res = *(new string (str));
    typedef string::const_iterator sit;
    typedef string::const_reverse_iterator srit;

    sit left = res.begin();
    sit last = res.end();

    srit right = res.rbegin();
    srit first = res.rend();

    while (::isspace(*left) && left != last)
      left++;

    while (::isspace(*right) && right != first)
      right++;

    if (left != res.begin())
      res.erase(res.begin(), left);

    if (right != res.rbegin())
      res.erase((--right).base()-1);

    return res;
  }

  const char *hey(const char* query)
  {
    string q (query);
    q = trim(q);
    const char l = q.back();

    if ( is_all_upcase(q) && ! is_all_numbers(q))
          return "Whoa, chill out!";
        else if (l == '?')
          return "Sure.";
        else if (q.empty())
          return "Fine. Be that way!";
        else
          return "Whatever.";
  }
};
