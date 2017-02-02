#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <boost/regex.hpp>
#include "word_count.h"

using namespace std;

static const string whitespace (" \t\n,");

namespace word_count
{
  static bool keep_char(const char c)
  {
    return isalnum(c) || isspace(c) || c == ',' || c == '\'';

  }

  static bool is_empty(string s)
  {
    return s.empty();
  }

  static vector<string> tokenize(const string phrase)
  {
    vector<string> &res = *(new vector<string>);
    boost::regex pattern {"[a-zA-Z0-9']+"};
    boost::regex quote {"(^'|'$)"};
    boost::sregex_iterator it(phrase.begin(), phrase.end(), pattern);
    boost::sregex_iterator end;

    for (; it != end; ++it)
    {
      string s = boost::regex_replace(it->str(), quote, "");
      transform(s.begin(), s.end(), s.begin(), ::tolower);
      if (s.length() > 0)
      {
        res.push_back(s);
      }
    }
    return res;
  }

  map<string, int> words(const char *words)
  {
    map<string, int> &res = *(new map<string,int>);
    vector<string> tokens = tokenize(string(words));

    for (string w : tokens)
      {
        res[w]++;
      }
    //  tokenize(string("abc def ghi"));
    return res;
  }
};
